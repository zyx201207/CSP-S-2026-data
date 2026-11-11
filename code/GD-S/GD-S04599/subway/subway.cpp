#include<bits/stdc++.h>
using namespace std;
struct edge{
	int sub,to,time;
};
const int N=1000;
int c,n,m,d,p,a[N],w[N][N],t[N];
vector<vector<edge> > v; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int k,i=1;i<=n;i++){
		cin>>k;
		vector<int> subway;
		for(int x,j=1;j<=2*k;j++){
			cin>>x;subway.push_back(x);
			cin>>w[k][x];
		}
		for(int j=1;j<=k;j++){
			for(int y=j+1;y<=k;y++){
				v[subway[j]].push_back({i,subway[y],0});
				v[subway[y]].push_back({i,subway[j],0});
			}
		}
	}
	
	return 0;
}

