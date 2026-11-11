#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+5,inf = 4e18;
int a[N],f[N][N],g[N][N],n,cc,d,t;
inline read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=g[i][k]*g[k][j];
				}else if(f[i][k]+f[k][j]==f[i][j]){
					g[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
	}
}
void solve(){
	cin >> n >> d;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			f[i][j]=inf;
			g[i][j]=0;
		}
	}
	for(int i = 1;i<=n;i++){
		f[i][i]=0,g[i][i]=1;
	}
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(abs(a[i]-a[j])<=d){
				f[i][j]=f[j][i]=1;
				g[i][j]=g[j][i]=1;
			}
		}
	}
	floyd();
	int ans = 0;
	
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(g[i][j]==2) ans++;
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> cc>>t;
	while(t--) solve();
	return 0;
}
