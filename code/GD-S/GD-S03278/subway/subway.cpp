#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
int w[N][5];//w[x]指第x个站从地铁口到站厅的距离
//有第几条线经过 ，有多少条线换乘 
vector<int>G[N];//第x个站有那几条线经过 
int a[N][N],t[N][N];
int a1[N];//第x条线有几个站 
int www;
int dfs(int x,int y){
	int vis[N];
	memset(vis,INF,sizeof(vis));
	queue<int>q;
	queue<int>q2;
	int now1;
	int www;
	for(int q1:G[x]){
		for(int k=1;k<=a1[q1];k++){
			if(a[q1][k]==x)now1=t[q1][k];
		}
		for(int i=1;i<=a1[q1];i++){
			if(a[q1][i]==y&&now1<vis[a[q1][i]])www=q1;
		    vis[a[q1][i]]=min(vis[a[q1][i]],now1);
			for(int p:G[a[q1][i]]){
			    if(p!=q1){
			    	q.push(p);
			    	int df=a[q1][i];
			    	int df1;
			    	for(int j=1;j<=a1[p];j++){
			    		if(a[p][j]==df)df1=j;
					}
			    	q2.push(now1+t[q1][i]+t[p][df1]);
				}
			}
	    } 
	}
	while(!q.empty()){
		int ff=q.front();
		q.pop();
		now1=q2.front();
		q2.pop();
		for(int i=1;i<=a1[ff];i++){
			if(a[ff][i]==y&&now1<vis[a[ff][i]])www=ff;
		    vis[a[ff][i]]=min(vis[a[ff][i]],now1);
			for(int p:G[a[ff][i]]){
			    if(p!=ff){
			    	q.push(p);
			    	int df=a[ff][i];
			    	int df1;
			    	for(int j=1;j<=a1[p];j++){
			    		if(a[p][j]==df)df1=j;
					}
			    	q2.push(now1+t[ff][i]+t[p][df1]);
				}
			}
	    } 
	}
	return vis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i][1];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a1[i]=x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back(i);
			w[a[i][j]][3]++;
		}
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		int x,y;
		cin>>x>>y;
		sum+=w[x][1];
		sum+=w[y][1];
		sum+=dfs(x,y);
		for(int k=1;k<=a1[www];k++){
			if(a[www][k]==y)sum+=t[www][k];
		}
		cout<<sum;
	}
	return 0;
}
