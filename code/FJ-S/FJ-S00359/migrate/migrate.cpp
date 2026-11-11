#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000005],d,dis[2000005],vis[2000005],cnt[2000005];
vector<int>v[2000005];
void dij(int s){
	priority_queue<pair<long long,int>>q;
	q.push({0,s});
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
	}
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	cnt[s]=1;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(auto to:v[x]){
			if(dis[to]>dis[x]+1){
				dis[to]=dis[x]+1;
				cnt[to]=cnt[x];
				q.push({-dis[to],to});
			}else if(dis[to]==dis[x]+1){
				cnt[to]++;
				q.push({-dis[to],to});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			v[i].clear();
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d){
					v[i].push_back(j);
				}else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
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
*/
