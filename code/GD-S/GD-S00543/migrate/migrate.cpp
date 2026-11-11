#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[5005],jl[5005],q[5005],minn[5005],cnt[5005];
bool vis[5005];
priority_queue<pair<int,int>> pq;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++) jl[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++) q[i]=q[i-1]+jl[i];
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=n;j++) minn[j]=1e18;
			vis[i]=1;
			pq.push({0,i});
			while(!pq.empty()){
				int u=pq.top().second,dis=pq.top().first;
				pq.pop();
				for(int j=u+1;j<=n;j++){
					if(q[j]-q[u]<=d){
						if(!vis[j]){
							pq.push({dis+1,j});
							minn[j]=dis+1;
							vis[j]=1;
						}
						if(dis+1==minn[j]) cnt[j]++;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
			for(int j=1;j<=n;j++) cnt[j]=0,vis[j]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
