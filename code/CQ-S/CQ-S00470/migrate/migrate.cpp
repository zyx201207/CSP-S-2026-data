#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,d,ans,x[305],k[305];
vector<int>g[305];
struct node{
	int id,sum; 
}; 
bool bfs(int s,int t){
	queue<node>q;
	q.push({s,0});
	for(int i=1;i<=n;i++)k[i]=INT_MAX;
	k[s]=0;
	int num=0,mint=INT_MAX;
	while(!q.empty()){
		int u=q.front().id,sum=q.front().sum;
		q.pop();
		if(u==t){
			if(mint==INT_MAX){
				mint=sum,num++;
			}else{
				if(sum==mint)num++;
			}
		}
		if(u>t)continue;
		if(sum>=mint)continue; 
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(k[v]>=k[u]+1){
				k[v]=k[u]+1;
				q.push({v,sum+1});
			}
		
		}
	}
	return num==2?true:false; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d)g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)==true)ans++;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
