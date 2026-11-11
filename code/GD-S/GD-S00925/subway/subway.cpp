#include<bits/stdc++.h>
using namespace std;
int C,m,n,D,q;
int w[500010];
int a[500010],t[500010];
long long dp[1010][1010];
vector<int> z[500010];//这个点有哪些边 
vector<int> f[510];//这个边有哪些点 
bool vf[500010],vz[510];
void solve1(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(i==k)  continue;
			for(int j=1;j<=m;j++){
				if(i==j||j==k)  continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<'\n';
	}
}
int dis[510];
struct node{
	int i,step;
};
void bfs(){
	queue<node> que;
	que.push(node{1,1});dis[1]=1;
	for(int i=1;i<=m;i++)  vz[i]=false;
	for(int i=1;i<=n;i++)  vf[i]=false;
	vz[1]=true;
	while(!que.empty()){
		node tmp=que.front();que.pop();
		int len=f[tmp.i].size();
		for(int i=0;i<len;i++){
			int v=f[tmp.i][i];
			if(vf[v])  continue;
			vf[v]=true;
			int len2=z[v].size();
			for(int j=0;j<len2;j++){
				int v2=z[v][j];
				if(vz[v2])  continue;
				vz[v2]=true;
				dis[v2]=tmp.step+1;
				que.push(node{v2,dis[v2]});
			}
		}
	}
}
int fnum=-1;
void solve2(){
	bfs();
	while(q--){
		int x,y;cin>>x>>y;
		int lx=z[x].size(),ly=z[y].size();
		int num=2147483647;
		for(int i=0;i<lx;i++){
			for(int j=0;j<ly;j++){
				int vx=z[x][i],vy=z[y][j];
				int tmp=abs(dis[vx]-dis[vy]);
				num=min(num,tmp);
				if(num==0)  break;
			}
			if(num==0)  break;
		}
		cout<<1LL*(num*2+2)*fnum+w[x]+w[y]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		if(m>500)  break;
		for(int j=1;j<=m;j++){
			dp[i][j]=2147483647360399;
		}
	}
	bool ff=true;
	for(int k=1;k<=n;k++){
		int len;cin>>len;
		for(int i=1;i<=len;i++){
			cin>>a[i]>>t[i];
			if(fnum==-1){
				fnum=t[i];
			}
			if(t[i]!=fnum)  ff=false;
			if(ff){
				z[a[i]].push_back(k);
				f[k].push_back(a[i]);
			}
			for(int j=1;j<i;j++){
				if(m>500)  break;
				dp[a[j]][a[i]]=t[i]+t[j];
				dp[a[i]][a[j]]=t[i]+t[j];
			}
		}
	}
	if(m<=500)  solve1();
	else  solve2();
	return 0;
}
//long long
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 2 5 20 2
4 1 9 2 5
3 1 5 2 5 4 5
3 2 5 3 5 5 5
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

