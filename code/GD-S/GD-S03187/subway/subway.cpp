#include<bits/stdc++.h>
using namespace std;
const int N=5e3+3;
int c,n,m,d,q,a[N][N],k[N];
long long ww[N],t[N][N],e[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> ww[i];
	}
	for(int i=1;i<=n*m+m;i++){
		for(int j=1;j<=n*m+m;j++){
			e[i][j]=0x3f3f3f3f;
		}
		e[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			if(j>1){
				e[a[i][j]+i*m][a[i][j-1]+i*m]=0LL;
				e[a[i][j-1]+i*m][a[i][j]+i*m]=0LL;
			}
			e[a[i][j]+i*m][a[i][j]]=t[i][j];
			e[a[i][j]][a[i][j]+i*m]=t[i][j];
		}
		
	}
	for(int k=1;k<=n*m+m;k++){
		for(int i=1;i<=n*m+m;i++){
			for(int j=1;j<=n*m+m;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[j][k]);
			}
		}	
	}
	for(int i=1,xx,yy;i<=q;i++){
		cin >> xx >> yy;
		long long aaa=ww[xx]+ww[yy]+e[xx][yy];
		cout << aaa << "\n" ;
	}
	return 0;
} 
