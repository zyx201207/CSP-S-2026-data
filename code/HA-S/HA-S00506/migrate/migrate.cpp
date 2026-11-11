#include<bits/stdc++.h>
using namespace std;
int C,T,n,di,a[200005],d[200005],ans[3005][3005];
vector<int> ve[200005];
int cnt;
bool vis[200005];
void bfs(int s){
	memset(d,0x3f,sizeof(d));
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	d[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		
		for(int i=0;i<ve[x].size();i++){
			int y=ve[x][i];
			//cout<<y<<" ";
			d[y]=min(d[x]+1,d[y]);
			ans[y][d[x]+1]++;
			q.push(y);
		}
	}
	//cout<<1;
	for(int i=1;i<=n;i++){
		if(i<=s)continue;
		//cout<<d[i]<<" ";
		if(ans[i][d[i]]==2)cnt++;
	}//cout<<cnt<<" ";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>di;
		for(int i=1;i<=n;i++){
//			while(!ve[i].empty()){
//				ve[i].pop_back();
//				
//			}
			ve[i].erase(ve[i].begin(),ve[i].end());
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i-1;j++){
				if(a[i]-a[j]<=di)ve[j].push_back(i);
			}
			if(i>1)ve[i-1].push_back(i);
		}
		for(int i=1;i<=n;i++){
			bfs(i);//cout<<i<<" ";
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
