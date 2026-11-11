#include<bits/stdc++.h>
#define int long long
#define ls first
#define rs second
using namespace std;
const int MaxN=2e6+5;
int C,T;
int n,d,x[MaxN],f[MaxN],dis[MaxN];
vector<int> to[MaxN];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){
			to[i].clear();
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				to[i].push_back(j);
			}
		} 
		int ans=0;
		queue<pair<int,int> > q;
		for(int s=1;s<n;s++){
			for(int t=s;t<=n;t++) f[t]=0,dis[t]=1e9;
			q.push({s,0});
			while(q.size()){
				int u=q.front().ls,w=q.front().rs;
				//cout<<u<<' '<<w<<'\n';
				q.pop();
				if(dis[u]>w) dis[u]=w,f[u]=0;
				if(dis[u]==w) f[u]++;
				if(dis[u]<w) continue;
				if(f[u]<=3){
					for(auto v:to[u]){
						q.push({v,w+1});
					}
				}
			}
			for(int t=s+1;t<=n;t++) ans+=(f[t]==2);
			//cout<<'\n';
		}
		cout<<ans<<'\n'; 
	}
	else cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
