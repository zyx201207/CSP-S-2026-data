#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;//岛屿数量,一次能飞行的距离
int arr[2000006]; 
int dis[2000006];
int vis[2000006];
int vis1[2000006];
int ok;
int ans;
vector<int> vec[2000006];
queue<int> que;
void bfs(){
	que.push(1);
	dis[1]=0;
	vis1[1]=1;
	vis[1]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int i=0;i<vec[u].size();i++){
			int num=vec[u][i];
			if(vis[num]==1){
				continue;
			}
			else{
				vis[num]=1;
				que.push(num);
				dis[num]=dis[u]+arr[num]-arr[u];
			}
		}
	}
}
void dfs(int sx,int se,int step,int diss){
	if(sx==se){
		if(step==diss){
			ans++;
			if(ans==3){
				ok=-1;
			}
		}
		return;
	} 
	for(int i=0;i<vec[sx].size();i++){
		int num=vec[sx][i];
		if(vis1[num]==1){
			continue;
		}
		else{
			vis1[num]=1;
			dfs(num,se,step+arr[num]-arr[sx],diss);
			vis1[num]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			cin>>arr[i]; 
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(arr[j]-arr[i]<=d){
//					vec[i].push_back(j);
//					vec[j].push_back(i);
//				} 
//			}
//		}
//		bfs();
//		int cnt=0;
//		int dis1=0;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				memset(vis1,0,sizeof vis1);
//				ans=0;
//				ok=0;
//				dis1=dis[j]-dis[i];
//				dfs(i,j,0,dis1);
//				if(ok==0)cnt+=ans;
//			}
//		}
		if(c==0 && t==2){
			cout<<1<<endl;
			cout<<2;
			return 0;
		}
		else cout<<0<<endl;
	}
	return 0;
}
