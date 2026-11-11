#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int dis[500005],w[500005],len[100006],c,n,m,d,q,a[501][50005],t[501][50005];
struct tt{
	int id,z;
	friend bool operator <(tt a,tt b){
		return a.z>b.z;
	}
};
vector<int> v[1000006];
int bfs(int st,int ed){
	for(int i=0;i<=m;i++)dis[i]=1e9;
	priority_queue<tt> q;
	while(!q.empty())q.pop();
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		tt qu=q.top();
		q.pop();
		int id=qu.id;
		if (id==ed)return qu.z;
		for(int i:v[id]){
			for(int j=1;j<=len[i];j++){
				int to=a[i][j],sp=dis[qu.id]+t[i][id]+t[i][to];
				if(dis[to]<=sp||id==to)continue;
				dis[to]=sp;
				q.push({to,dis[to]});
			}
		}
	}
}
int main(){
	op();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][a[i][j]]);
			v[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		cout<<bfs(x,y)+w[x]+w[y]<<"\n";
	}
}
