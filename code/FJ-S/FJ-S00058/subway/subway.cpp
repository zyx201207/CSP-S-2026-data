#include <bits/stdc++.h>
using namespace std;

int fl[1002][1002],w[1002],k[1002],a[1002][1002],t[1002][1002];
const int inf=2147483647;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			if (i!=j){
				fl[i][j]=inf;
			}
		}
	}
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		fl[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
		fl[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
	}
	for (int k=1;k<=m;k++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				fl[i][j]=min(fl[i][j],fl[i][k]+fl[k][j]);
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+fl[x][y]<<endl;
	}
	return 0;
}

