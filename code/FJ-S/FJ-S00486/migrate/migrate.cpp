#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000005];
int dis[2000005][2];int n,d;priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dij(int uu,int type){
	for(int i=1;i<=n;i++)dis[i][type]=1;
	dis[uu][type]=0;
	while(!q.empty())q.pop();
	q.push({0,uu});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(int i=1;i<=n;i++){
			if(i==u){
				continue;
			}
			if(abs(a[i]-a[u])<=d&&dis[u][type]+1<dis[i][type]){
				dis[i][type]=dis[u][type]+1;
				q.push({dis[i][type],i});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dij(n,0);
		dij(1,1);
		int res=0;
		/*for(int i=1;i<=n;i++){
			cout<<dis[i][0]<<" "<<dis[i][1];
			cout<<endl;
		}*/
		for(int i=2;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(dis[i][0]==dis[j][1]||dis[i][1]==dis[j][0])res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
