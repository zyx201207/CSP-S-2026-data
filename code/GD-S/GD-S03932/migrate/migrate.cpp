#include <bits/stdc++.h>
#define ll long long
using namespace std;
int C,T,n;
ll d,x[2000010],nxt[2000010],to[2000010],f[2000010],h[2000010];
vector<int> g[2000010];
int tag[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],g[i].shrink_to_fit(),g[i].clear(),tag[i]=0,to[i]=0,f[i]=h[i]=0ll;
		int p=n;
		for(int i=n;i>=1;i--){
			while(p>i&&x[p]-x[i]>d) p--;
			nxt[i]=p;
			g[p].push_back(i);
		}
		for(int i=2;i<=n;i++){
			if(x[nxt[i]]-x[i-1]<=d) tag[i]++;
			if(i>=3&&x[nxt[i]]-x[i-2]<=d) tag[i]++;
		}
		int now=n;
		for(int i=n;i>=1;i--){
			if(tag[i]==1) to[i]=now;
			if(tag[i]!=0) now=i;
		}
		ll ans=0ll;
		for(int i=n;i>=1;i--){
			if(tag[nxt[i]]==0){
				f[i]+=f[nxt[i]];
				h[i]+=h[nxt[i]];
			}
			if(i>=3) for(auto u:g[i]){
				if(u==i) continue;
				if(u<=i-2) f[u]+=1ll*(nxt[i-1]-nxt[i-2]);
				h[u]+=1ll*(nxt[i]-nxt[i-1]);
			}
			if(tag[i]==1) for(auto u:g[i]){
				if(u==i) continue;
				f[u]+=h[i];
			}
		}
		for(int i=1;i<=n;i++) ans+=f[i];
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 4
-3 0 1 2 3 4

0 1
6 3
0 1 2 3 4 7

*/
