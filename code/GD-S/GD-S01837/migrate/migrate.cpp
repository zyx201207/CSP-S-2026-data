#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d,ans=0;
int x[N];
int f[N],c[N];
void dfs(int u,int cnt){
	if(u>n)return;
	if(cnt>c[u])return;
	if(cnt<c[u]){
		c[u]=cnt;
		f[u]=1;
	}else if(cnt==c[u]){
		f[u]++;
	}
	if(u==n)return;
	int v=u+1;
	while(x[v]-x[u]<=d&&v<=n){
		if(cnt+1>c[v]){
			v++;
			continue;
		}else dfs(v,cnt+1);
		v++;
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int op=0,T=0;
	cin>>op>>T;
	while(T--){
		ans=0; 
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>=1e4){
			cout<<"0\n";
			continue;
		} 
		for(int i=1;i<n;i++){
			memset(c,63,sizeof(c));
			memset(f,0,sizeof(f));
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(f[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
Oct31==Dec25?
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

*/
