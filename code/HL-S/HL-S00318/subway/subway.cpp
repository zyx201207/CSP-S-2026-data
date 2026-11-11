#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=5e3+5;
long long c,n,m,d,qq;
long long ans;
int w[N],a[M],t[M];
long long dis[M][M];
//vector<pair<long long,int> > v[N];//length,point_name
long long v[M][M];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q; 
void dijkstra(int s){
	for (int i=1;i<=m;i++){
		dis[s][i]=INT_MAX;
	}
	dis[s][s]=0;
	q.push({0,s});
	while (!q.empty()){
		int x=q.top().second;
		q.pop();
		for (int i=1;i<=m;i++){
			if (v[x][i]!=0){
				if (dis[s][i]>dis[s][x]+v[x][i]){
					dis[s][i]=dis[s][x]+v[x][i];
					q.push({dis[s][i],i});
				}
			}
				
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>qq;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k; 
		cin>>k;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for (int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if (j<2) continue;
			for (int l=1;l<j;l++){
				v[a[j]][a[l]]=t[j]+t[l];
				v[a[l]][a[j]]=t[j]+t[l];
			}
		}
	}
	for (int i=1;i<=m;i++){
		dijkstra(i);
	}
	for (int i=1;i<=qq;i++){
		int a,b;
		cin>>a>>b;
		cout<<dis[a][b]+w[a]+w[b]<<"\n";
	}
	return 0;
}
