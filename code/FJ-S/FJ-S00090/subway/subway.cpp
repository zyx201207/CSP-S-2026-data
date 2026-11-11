#include <bits/stdc++.h>
using namespace std;
int c,n,m,dd,q;
int w[500005];
int k;
int a[505][2005], t[505][2005];
int d[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>> dd>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	memset(a,0,sizeof(a));
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[k][j]>>t[k][j];
			if(c>=9&&c<=11){
				for(int o=1;o<=j;++o){
					d[a[k][o]][a[k][j]]=min(d[a[k][o]][a[k][j]],t[k][o]+t[k][j]);
					d[a[k][j]][a[k][o]]=min(d[a[k][j]][a[k][o]],t[k][o]+t[k][j]);
				}
            }
		}
	}
	for(int o=1;o<=n;++o){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+d[x][y]<<endl;
	}
	return 0;
}

