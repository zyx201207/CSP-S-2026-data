#include<bits/stdc++.h>
using namespace std;
/*
typedef pair<int,int> PII;
struct Edge{
	int w,
};*/
const int maxm=500005;
const int maxn=505;

int c,n,m,d,q,a[maxm],w[maxm],t[maxm],dis[maxm],k;
/*
vector<Edge>
void dijkstra(int s){
	dis[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> >pq;
	pq.push({s,0})
	while(!pq.empty()){
		int v=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		for(auto e:g)
	}
}
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x]+t[y]<<endl;
	}
	return 0;
}

