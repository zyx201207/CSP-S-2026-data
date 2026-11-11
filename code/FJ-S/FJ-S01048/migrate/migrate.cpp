#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,fr[2000005],ans=0;
		long long d,a[2000005];
		vector<int>adj[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[i]-a[mid]>d){
					l=mid+1;
				}
				else{
					fr[i]=mid;
					r=mid-1;
				}
			}
			for(int j=fr[i];j<i;j++){
				adj[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			int vis[2000005],dis[2000005];
			queue<int>q;
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f,sizeof(dis));
			dis[i]=0;
			q.push(i);
			while(!q.empty()){
				int be=q.front();
				q.pop();
				vis[be]++;
				for(int j:adj[be]){
					if(dis[j]>=dis[be]+1){
						dis[j]=dis[be]+1;
						q.push(j);
					}
				}
			}
			for(int j=i;j<=n;j++){
				if(vis[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
