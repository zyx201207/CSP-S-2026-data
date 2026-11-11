#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5005;
LL n,m,d,q,hyw,w[N],k[N],a[5005][N],t[5005][N],x[N],y[N],f[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>hyw>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(j%2==0) cin>>t[i][j/2];
			else cin>>a[i][(j+1)/2];
		}
	}for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int s=j+1;s<=k[i];s++){
				f[a[i][j]][a[i][s]]=t[i][s]+t[i][j];
					f[a[i][s]][a[i][j]]=t[i][s]+t[i][j];
			}
		}
	}for(int i=1;i<=m;i++) f[i][i]=0;
	for(int s=1;s<=m;s++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][s]+f[s][j]);
			}
		}
	}for(int i=1;i<=q;i++){
		cout<<f[x[i]][y[i]]+w[x[i]]+w[y[i]]<<"\n";
	}
    return 0;
}
