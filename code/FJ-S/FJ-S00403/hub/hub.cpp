#include <bits/stdc++.h>
using namespace std;
	int c=0,m=0,n=0,d=0,q=0;
	int k[501]={0},a[501][500001]={0},t[501][500001]={0};
	int w[500001]={0};
	int x[100001]={0},y[100001]={0};
	int stationsubways[500001][21]={1};
	long long tft[1001][1001]={0};
	long long searchroad(int from,int gotop){
		if (from==gotop) return 0;
		if (tft[from][gotop]!=0) return tft[from][gotop];
		long long temptime=0;
		long long mintime=0;
		for (int i=1;i<=stationsubways[from][0];++i){ 
		for (int j=1;j<=k[stationsubways[from][i]];++j){
			temptime=(searchroad(a[stationsubways[from][i]][j],gotop)+(long long)t[stationsubways[from][i]][j]);
			if (mintime==0||temptime<mintime) mintime=temptime;
		}
	}
	return mintime;
	}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i){
	cin>>w[i];
	}
	for (int i=1;i<=n;++i){
	cin>>k[i];
	for (int j=1;j<=k[i];++j){
	cin>>a[i][j]>>t[i][j];
	stationsubways[a[i][j]][stationsubways[a[i][j]][0]]=i;
	}
	}
	long long tmptmp;
	for (int j=1;j<=q;++j){
	cin>>x[j]>>y[j];
	tmptmp=searchroad(x[j],y[j])+(long long)w[x[j]]+(long long)w[y[j]];
	cout<<tmptmp;
	}
	return 0;
} 
