#include<bits/stdc++.h>
using namespace std;
int w[505],k[505];
int a[505][1005],t[505][1005];
int x[100005],y[100005],f[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=n;j++){
			for(int jj=1;jj<=k[j];jj++){
				if(a[j][jj]==x[i])ans+=t[x[i]][jj]+w[x[i]];
				break;
			}
		}
		for(int j=1;j<=n;j++){
			for(int jj=1;jj<=k[j];jj++){
				for(int jjj=x[i];jjj<=y[i];jjj++){
					if(a[jj][q]==jjj&&f[jjj]==0){
						ans+=t[x[i]][jj]+w[i];
						f[jjj]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
