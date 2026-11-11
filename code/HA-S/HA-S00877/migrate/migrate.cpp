#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll in(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')f=(ch=='-')?(-1):(f),ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void out(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar((x%10)^48);
}
const int N=2e6+5;
int T,n,c;
ll d,x[N],pt[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in();T=in();
	while(T--){
		n=in();d=in();
		for(int i=1;i<=n;i++){
			x[i]=in();
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;g[i]=1;
			for(int j=i+1;j<=n;j++){
				f[j]=N;g[j]=0;
				int o=j;
				while(i<=o-1&&x[j]-x[o-1]<=d){
				//	cout<<o-1<<" "<<f[o-1]<<"\n";
					o--;
					if(f[o]+1==f[j])g[j]+=g[o];
					if(f[o]+1<f[j])f[j]=f[o]+1,g[j]=g[o];
				}
			//	cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[j]<<"\n";
				if(g[j]==2)ans++;
			}
		}
		out(ans);puts("");
	}
	return 0;
}
