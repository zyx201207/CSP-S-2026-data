#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N=2e6+10;
int f[N],g[N];
int a[N],s[N],n,d;
int c,T,ans;
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0x3f,sizeof f);
		memset(g,0,sizeof g);
		f[i]=0;
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i and a[j]-a[k]<=d;k--){
				if(f[k]+1<f[j]){
					f[j]=f[k]+1;
					g[j]=1;
				}
				else if(f[k]+1==f[j])g[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(g[i]==2)ans++; 
		}
	} 
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}return 0;
}
