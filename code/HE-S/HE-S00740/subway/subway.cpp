#include <bits\stdc++.h>
using namespace std;

long long k[500005];
long long k0[505];
long long a[505][505];
long long t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//Í¼ÂÛ+Ì°ÐÄ 
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(long long i=1;i<=m;i++){
		cin >> k[i];
	}
	for(long long i=1;i<=n;i++){
		cin >> k0[i];
		for(long long j=1;j<=k0[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	long long ans=0;
	for(long long p=1;p<=q;p++){
		long long x,y;
		cin >> x >> y;
		ans+=k[x]+k[y];
		for(long long i=1;i<=n;i++){
			bool x1=0,y1=0;
			long long xi,xj,yi,yj;
			for(long long j=1;j<=k0[i];j++){
				if(a[i][j]==x){
					x1=1;
					xi=i;
					xj=j;
				}
				if(a[i][j]==y){
					y1=1;
					yi=i;
					yj=j;
				}
			}
			if(x1==1&&y1==1){
				ans+=t[xi][xj]+t[yi][yj];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
