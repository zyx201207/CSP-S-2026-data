#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[100001],a[501][10001],t[501][10001],cv[10001][501],bh[10001],dt[5001][5001],mnb[100001][2],yg[10001][501];
vector<long long>p[100001];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][j];
			p[a[i][j]].push_back(a[i][j-1]);
			p[a[i][j-1]].push_back(a[i][j]);
			if(bh[a[i][j]]==0){
				cv[a[i][j]][i]=t[i][j];
				bh[a[i][j]]=i;
				yg[a[i][j]][i]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(dt[x][y]==0){
			cout<<w[x]+w[y]+cv[x][bh[x]]+cv[y][bh[y]]<<endl;
		}
		else{
			cout<<w[x]+w[y]<<endl;
		}
	}
	return 0;
}
