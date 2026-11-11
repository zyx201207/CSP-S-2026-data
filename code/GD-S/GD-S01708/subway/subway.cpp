#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,sta,num1,num2,tmp1,tmp2;
long long ans[1001][1001],w[1001],t[501][1001],dis[1001];
struct node{
	int id;long long cost;
	bool operator<(const node &b)const{return cost>b.cost;}
};
int line[1001][21],cnt[1001];
vector<int>g[1001][21],sx[501];
bool flag=1;
void bfs(int st,int ed){
	queue<pair<int,int> >q;
	bool vis[500001]={0};
	vis[st]=1;
	q.push({st,0});
	while(!q.empty()){
		int u=q.front().first,tt=q.front().second;q.pop();
		if(u==ed){
			cout<<1ll*tt*num2+w[st]+w[ed]<<'\n';
			return;
		}
		for(int i=1;i<=cnt[u];i++){
			int line_id=line[u][i];
			int qdindex;
			for(int j=0;j<sx[line_id].size();j++)
			    if(sx[line_id][j]==u){
			    	qdindex=j;
			    	break;
				}
			for(int j=qdindex+1;j<sx[line_id].size();j++){
				int to=sx[line_id][j];
				if(vis[to])continue;
				vis[to]=1;
				q.push({to,tt+1});
			}
		}
	}
}
void dij(int st,int ed){
	priority_queue<node>q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.cost>dis[u.id])continue;
		for(int i=1;i<=cnt[u.id];i++){
			int line_id=line[u.id][i];
			int qdindex;
			for(int j=0;j<sx[line_id].size();j++)
			    if(sx[line_id][j]==u.id){
			    	qdindex=j;
			    	break;
				}
			for(int j=qdindex+1;j<sx[line_id].size();j++){
				int to=sx[line_id][j];
				long long bq=t[line_id][u.id]+t[line_id][to];
				if(u.cost+bq>dis[to])continue;
				dis[to]=u.cost+bq;
				q.push({to,dis[to]});
			}
		}
	}
	//for(int i=1;i<=m;i++)cout<<dis[i]<<' ';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
 	for(int i=1;i<=n;i++){
 	    cin>>k;
		 for(int j=1;j<=k;j++){
		 	tmp1=num1,tmp2=num2;
		 	scanf("%lld%lld",&num1,&num2);
		 	if(tmp2!=num2)flag=0;
		 	sx[i].push_back(num1);
		 	cnt[num1]++;
		 	line[num1][cnt[num1]]=i;
		 	t[i][num1]=num2;
		 	if(j==1)continue;
		 	g[tmp1][cnt[tmp1]].push_back(num1);
		 }
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		memset(dis,63,sizeof(dis));
		if(flag)bfs(st,ed);
		else{
		dij(st,ed);
		cout<<dis[ed]+w[st]+w[ed]<<'\n';	
		}
	}
 	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
32 17*/
