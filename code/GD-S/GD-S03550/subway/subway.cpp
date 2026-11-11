#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],a[505][2],e[5005][5005];
struct node{
	int k,dis;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j][0]>>a[j][1];
			for(int p=1;p<j;p++){
				e[a[j][0]][a[p][0]]=e[a[p][0]][a[j][0]]=a[j][1]+a[p][1];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		priority_queue<node>q;
		bool vis[5005]={};
		int dis[5005];
		memset(dis,0x3f,sizeof(dis));
		dis[x]=0;
		q.push({x,0});
		while(!q.empty()){
			int k=q.top().k;
			q.pop();
			if(vis[k])continue;
			vis[k]=true;
			for(int j=1;j<=m;j++){
				if(!e[k][j])continue;
				if(dis[j]>dis[k]+e[k][j])dis[j]=dis[k]+e[k][j],q.push({j,dis[j]});
			}
		}
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
