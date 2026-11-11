#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define ll long long
ll c,n,m,d,q,k,p,t;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ll Time[m];
	bool line_point[n][m];
	for(auto &i:line_point) for(ll &j:i) j=false;
	ll line_change[n][m];
	for(auto &i:line_change) for(ll &j:i) j=-1;
	for(int i=0;i<m;i++) cin>>Time[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<2*k;j++){
			cin>>p>>t;
			line_point[n][p]=true;
			line_change[n][p]=t;
		}
	}
	ll graph[n][n];
	for(auto &i:graph) for(ll &j:i) j=1048576;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;i++){
			int res=1048576;
			for(int k=0;k<m;k++){
				if(line_point[i][k] && line_point[j][k]) res=min(res,line_change[i][k]+line_change[j][k]);
			}
			graph[i][j]=res;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
	while(q--){
		cout<<res;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
