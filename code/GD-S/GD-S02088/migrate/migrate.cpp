#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<pii> g[100005];
int dist[5005],mp[5005],ans,a[2000005];
bool st[5005];
void dijkstra(int s){
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[s]=0;
	mp[s]=1;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,s});
	while(q.size()) {
		auto it=q.top();
		q.pop();
		if(st[it.second]) continue;
		else st[it.second]=1;
		for(auto i:g[it.second]){
			int j=i.first,w=i.second;
			if(dist[j]>dist[it.second]+w){
				dist[j]=dist[it.second]+w;
				mp[j]=mp[it.second];
				q.push({dist[j],j});
			}else if(dist[j]==dist[it.second]+w) {
				mp[j]+=mp[it.second];
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freoepn("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		int n,d;
		cin>>n>>d;
		if(n<=500){
			for(int i=1;i<=n;i++) cin>>a[i],g[i].clear();
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) g[i].push_back({j,1});
				}
			} 
			for(int i=1;i<=n;i++){
				dijkstra(i);
				for(int j=1;j<=n;j++) if(mp[j]==2) ans++; 
			} 
			cout<<ans<<"\n";
		}else{
			for(int i=3;i<=n;i++){
				int l=i-1,cnt=0;
				while(a[i]-a[l]<=d){
					cnt++;
					l--;
				}
				if(cnt==2&&l>0) ans++;
				if(a[i]-a[i-1]>d) break;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
