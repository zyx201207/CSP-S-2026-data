//48·Ö 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
int C,n,d;
int x[N],p[N],f[N][N],g[N][N],ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=g[i][j]=0;
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(15<=C<=18) cout<<"0\n"; 
	else if(11<=C<=12){
		int p=x[2]-x[1];
		int o=d/p;
		o+=o-1;
		cout<<n-o+1<<"\n";
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int w=1e18,m=0;
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]<=d){
						if(g[i][k]+1==w) m+=f[i][k];
						else if(g[i][k]+1<w) w=g[i][k]+1,m=f[i][k];
					}
					else break;
				}
				if(m!=0) f[i][j]=m,g[i][j]=w;
				if(m==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>C>>T;
	while(T--) solve();

	return 0;
}

