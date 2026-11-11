#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,t,n,d;
int a[5005];
int dis[5005];
int p[5005];
int cnt[5005];
vector<int> e[5005];
priority_queue<pii,vector<pii>,greater<pii>> q;
int sum;
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
	for(int i=1;i<=n;i++){
		p[i]=dis[i];
	}
	memset(dis,0x3f,sizeof(dis));
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto v:e[u]){
			if(dis[v]>=dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
				if(dis[v]==p[v]){
					cnt[v]++;
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					e[i].push_back(j);
					e[j].push_back(i); 
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2){
					sum++;
				}
				cnt[j]=0;
			}
		}
		cout<<(sum>>1)<<"\n";
	}
	return 0;
} 
