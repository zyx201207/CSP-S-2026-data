#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define N 5002
#define M 2000005
using namespace std;
int read(){
	char c=getchar();
	int x=0; bool f=0;
	while(c<'0'||c>'9'){if(c=='-') f=1;	c=getchar();	}
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int INF=2e18+7,mod=7;
int C,T,n,d,a[N],f[N][N],g[N][N],ans;
void solve(){
	n=read(),d=read(); ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=INF,g[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			f[i][j]=1,g[i][j]=1;
		}
	for(int i=2;i<=n;i++){
		for(int l=1,r;l<=n-i+1;l++){
			r=l+i-1;
			for(int k=l;k<=r;k++){
				if(f[l][r]>f[l][k]+f[k][r]) f[l][r]=f[l][k]+f[k][r],g[l][r]=g[l][k]*g[k][r];
				else if(f[l][r]==f[l][k]+f[k][r]) g[l][r]+=g[l][k]*g[k][r]; 
			}
//			g[l][r]%=mod;
			g[l][r]=min(g[l][r],3ll);
			if(g[l][r]==2) ans++;
//			cout<<l<<" "<<r<<" "<<f[l][r]<<" "<<g[l][r]<<endl;
		}
	}
	write(ans);	putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--) solve();
    return 0;
}
