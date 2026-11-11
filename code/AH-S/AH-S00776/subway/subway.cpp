#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,lu,step;
};
vector<int>lu[5005];
int w[5005];
int g[5005];
vector<int>l[5005];
vector<int>q1[5005];
int t[1005][1005];
int lx[5005];
int dp[5005][505];
void bfs(int x,int y){
	node now,pos,next;
	queue<node>q;
	now.x=x;
	for(int i=0;i<lu[x].size();i++){
		now.lu=lu[x][i];
		now.step=t[x][lx[i]];
		q.push(now);
	}
	while(!q.empty()){
		pos=q.front();
		q.pop();
		if(pos.x==y){
			dp[y][pos.lu]=min(dp[y][pos.lu],pos.step+t[y][pos.lu]);
			continue;
		}
		//线路重选 
		for(int i=0;i<lu[pos.x].size();i++){
			next.step=pos.step;
			next.step+=t[pos.x][now.lu];
			for(int j=0;j<lu[pos.x].size();j++){
				node nxt;
				nxt.step=next.step;
				nxt.step+=t[pos.x][lu[pos.x][j]];
				if(dp[pos.x][pos.lu]<nxt.step){
					nxt.lu=lu[pos.x][j];
					nxt.x=pos.x;
					q.push(nxt);
				}
			}
		}
		
		//下一站
		for(int i=0;i<q1[pos.lu].size();i++){
			next.x=i;
			if(dp[i][pos.lu]<=pos.step)continue;
			next.step=pos.step;
			next.lu=pos.lu;
			next.x=q1[pos.lu][i];
			q.push(next);
		} 
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>g[i];
		for(int j=1;j<=g[i];j++){
			int ls;
			cin>>ls>>t[i][j];//第i个地铁站到第j条线 
			q1[i].push_back(ls);//第i号线有过第ls站 
			l[ls].push_back(i);//第ls个地铁站有第i号线 
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(dp,0,sizeof(dp));
		bfs(x,y);
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
