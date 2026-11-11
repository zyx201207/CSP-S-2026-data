#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 2000006
#define fi first
#define se second
int c,T,n,d,x[N],f[N][25];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
//	freopen("ans.out","w",stdout);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int l = 1,r=1;l <= n;l++){
			bool ff=true;
			if(r < l){
				r=l;
			}
			while(r+1<=n&&x[r+1]-x[l]<=d){
				r++;
				ff=false;
			}
			if(ff){
				f[l][0]=0;
			}else{
				f[l][0]=r;
			}
//			cout << l << " " << f[l][0] << endl;
		}
		for(int j = 1;j <= 21;j++){
			for(int i = 1;i <= n;i++){
				if(f[i][j-1]!=0){
					f[i][j]=f[f[i][j-1]][j-1];
				}
			}
		}
		int ans=0;
//		if(c<=10){
//			for(int i = 1;i <= n;i++){
//				int cnt=1;
//				for(int j = f[i][0];j;j=f[j][0],cnt++){
//					int v = f[j-1][0];
//					int u = f[i][0]-1;
//					for(int i = 1;i <= cnt;i++){
//						u=f[u][0];
//					}
//					if(u==v){
//						ans++;
//					}
//				}
//			}
//		}else{
			for(int i = 1;i <= n;i++){
				int t = i;
				for(int j = 21;j >= 0;j--){
					if(f[t][j]&&f[f[t][j]-1][0]){
						t=f[t][j];
						ans+=(1<<j);
					}
				}
			}
//		}
		
		cout << ans << endl;
		for(int i = 0;i <= n;i++){
			f[i][0]=0;
		}
	}
	return 0;
}
