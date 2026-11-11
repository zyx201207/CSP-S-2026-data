#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[100010],ww[100000],a[21][100000],t[21][100000];
const int inf=10000000;
struct datab{
	int v,w;
};
vector<datab> e[1000];
int dis(int s,int y){
	int d[100010];
	for(int i=1;i<=m;i++){
		d[i]=inf;
	}
	d[s]=0;
	for(int i=1;i<=m;i++){
		int flag=0;
		for(int u=1;u<=m;u++){
			for(int j=0;j<e[u].size();j++){
				datab f=e[u][j];
				if(d[f.v]>d[u]+f.w){
					d[f.v]=d[u]+f.w;
					flag=1;
				}
			}
		}		
		if(flag==0){
			break;
		}
	}
	return d[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				e[a[i][j-1]].push_back({a[i][j],t[i][j]+t[i][j-1]});
				e[a[i][j]].push_back({a[i][j-1],t[i][j]+t[i][j-1]});
			}	
		}
	}	
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis(x,y)+ww[x]+ww[y]<<endl;	
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
*/
