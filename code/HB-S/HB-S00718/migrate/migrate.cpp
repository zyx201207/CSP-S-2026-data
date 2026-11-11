#include<bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long RP=ULONG_LONG_MAX;
ll ceshi,t,n,k,a[5010],dis[5010],s[5010];
vector<ll> g[5010];
queue<ll> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ceshi>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=k) g[i].push_back(j);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			queue<ll> q;
			q.push(i);
			memset(dis,0x3f,sizeof(dis));
			dis[i]=0;
			memset(s,0,sizeof(s));
			s[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						s[v]=s[u];
						q.push(v);
					}
					else if(dis[v]==dis[u]+1){
						s[v]+=s[u];
						if(s[v]>=3) s[v]=9178;
					}
				}
			}
			for(int j=i;j<=n;j++){
				if(s[j]==2) ans++;
			}
			/*cout<<i<<":";
			for(int j=1;j<=n;j++){
				cout<<s[j];
			}
			cout<<"\n";*/
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/**∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅*/
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
