#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e6+10;
int c,t;
ll n,d;
ll a[N];
int cnt[N];
int dis[N];
vector<int> G[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				G[i].clear();
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						G[i].push_back(j);
					}
				}
			}
			for(int i=1;i<=n;i++){
				queue<int> q;
				q.push(i);
				for(int j=i;j<=n;j++){
					cnt[j]=0;
					dis[j]=1e9;
				}
				dis[i]=0;
				while(q.size()){
					int u=q.front();
					cnt[u]++;
					q.pop();
					for(int j=0;j<G[u].size();j++){
						int v=G[u][j];
						if(dis[u]+1>dis[v])continue;
						if(dis[u]+1<dis[v]){
							dis[v]=dis[u]+1;
							cnt[v]=0;
						}
						q.push(v);
					}
				}
				for(int j=i;j<=n;j++){
					if(cnt[j]==2){
						ans++;
					}
				}
			}
		}
		else{
			int step=d/(a[2]-a[1]);
			if(step>1){
				int len=2*step-1;
				ans=max(ans,n-len);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
