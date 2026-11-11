#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,dd,q,w[N],a[N],t[N],d[N+1001],last;
struct node{
	long long to,len;
};
vector<node> g[N];
set<pair<long long,long long> > heap;
void dij(int s){
	for(int i=1;i<=n+m;i++){
		d[i]=1e18;
	}
	d[s]=0;
	heap.insert({0,s});
	while(!heap.empty()){
		int v=heap.begin()->second;
		heap.erase(heap.begin());
		for(int i=0;i<g[v].size();i++){
			int to=g[v][i].to,len=g[v][i].len;
			if(d[to]>d[v]+len){
				heap.erase({d[to],to});
				d[to]=d[v]+len;
				heap.insert({d[to],to});
			}
		}
	}
}

bool flag,vis;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int maxx;
	for(int i=1;i<=n;i++){
		int k;
		maxx=max(maxx,i);
		cin>>k;
		if(k>2) flag=1;
		for(int j=1;j<=k;j++){
//			if(i==1&&last) last=t[j];
			cin>>a[j]>>t[j];
//			if(last&&last!=t[j]) vis=1;
			g[a[j]].push_back({i+m,t[j]});
			g[i+m].push_back({a[j],t[j]});
		}
	}
	if(flag==0){
		dij(1);
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<abs(d[r]-d[l])+w[l]+w[r]<<'\n';
		}
		return 0;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dij(l);
		cout<<d[r]+w[l]+w[r]<<'\n';
	}
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

0 2 5 20 2
4 1 9 2 5
3 1 1 2 1 4 1
3 2 1 3 1 5 1
2 3
1 2
*/
