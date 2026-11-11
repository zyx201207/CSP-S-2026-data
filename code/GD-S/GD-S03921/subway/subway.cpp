#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+10;
int c,n,m,d,q;
//分别表示测试点编号、地铁线路数、地铁站数、
//每个地铁站最多被几条线路经过以及出行计划数。
ll w[M];//依次表示从每个地铁站的地铁口走到站厅需要的时间。
int v2[N],a[M][N],a2[M];
vector<pair<int,int>> b[N];
vector<int> v[N];
void tr(int fa){
//	cout <<fa<<endl;
	for(int i=1;i<=n;i++){
		if(a[fa][i]==0)continue;
		for(int j=i+1;j<=n;j++){
			if(a[fa][i]==0)continue;
			b[i].push_back({j,a[fa][i]+a[fa][j]});
			b[j].push_back({i,a[fa][i]+a[fa][j]});
		}
	}
}
int dis[N][N],dis2[N][N],vis[N];
void df(int u){
	priority_queue<pair<int,int> >q;
	q.push({b[u][0].first,b[u][0].second});
	/*
	cout <<1;
		auto x=q.top();
		q.pop();
		int y=x.first,z=x.second;
		cout <<" "<<y<<" "<<z<<endl;
		*/
	vis[b[u][0].first]=1;
	dis[u][b[u][0].first]=b[u][0].second;
	while(!q.empty()){
	//	cout <<1<<endl;
		auto x=q.top();
		q.pop();
		int y=x.first,z=x.second;
	//	cout <<" "<<y<<" "<<z<<endl;
		for(int i=0;i<b[y].size();i++){
			int v=b[y][i].first,wi=b[y][i].second;
			
			if(vis[v]==0){
			//	cout <<v<<" "<<wi<<endl;
				if(wi+z<dis[u][v]){
					dis[u][v]=b[y][i].second+z;
					dis[v][u]=b[y][i].second+z;
					q.push({v,wi});
				}
			}
		}
	}
}
void f(int s1,int s2){
	int x=v2[s1],y=v2[s2];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			int l=v[s1][i],r=v[s2][j];
			/*
			cout <<a[l][s1]<<" "<<a[r][s2]<<" "<<dis2[i][j]<<endl;
			cout <<dis[s1][s2]<<"  "<<l<<" "<<r<<endl;
			*/
			if(l==r)continue;
		//	cout <<1<<endl;
			dis2[l][r]=min(dis2[l][r],dis[s1][s2]+a[l][s1]+a[r][s2]);
		}
	}
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	memset(dis,1e8+10,sizeof(dis));
	memset(dis2,1e8+10,sizeof(dis2));
	for(int i=1;i<=m;i++)cin >>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >>k;
		v2[i]=k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >>x>>y;
			a2[x]++;
			a[x][i]=y;
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++)if(a2[i]>1)tr(i);
	vis[1]=1;
	df(1);
	/*
	for(int i=1;i<=n;i++){
		cout <<i<<endl;
		for(int j=0;j<b[i].size();j++){
			cout <<b[i][j].first<<" "<<b[i][j].second<<endl;
		}
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f(i,j);
		} 
	}
	for(int k=1;k<=n;k++){
		for(int j=0;j<=v2[k];j++){
			for(int i=0;i<=v2[k];i++){
				int l=v[k][i],r=v[k][j];
				if(l==r)continue;
				dis2[l][r]=a[l][k]+a[r][k];
			}
		}
	}/*
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)cout <<dis[i][j]<<" ";
		cout <<endl;
	}
	*/
	while(q--){
		int x,y;
		cin >>x>>y;
		cout <<dis2[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
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
