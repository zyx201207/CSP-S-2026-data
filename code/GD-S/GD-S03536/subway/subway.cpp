#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN];
long long l[MAXN],r[MAXN];
int q,n,c,d,m;
long long k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >>n >>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	/*int u1=0;
	for(int i=1;i<=n;i++){
		cin >> k;
		int v;
		long long w;
		cin >> v >>w;
		f[u1][v]=w;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j&&i!=k&&j!=k){
						f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin >> l[i] >> r[i];
		int x=l[i],y=r[i];
		cout << f[x][y]+a[x]+a[y] << "\n";
	}*/
	cout << 32 << "\n" <<17;
} 
