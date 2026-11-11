#include <iostream>

#define gc getchar()
#define ll long long
using namespace std;
const int MAXN=2e6+114;

inline ll read(){
	ll p=0,k=1;
	char c=gc;
	while (c<'0'||c>'9') {
		if(c=='-') k=-k;
		c=gc;
	}
	while (c>='0'&&c<='9') p=p*10+c-'0',c=gc;
	return p*k;
}
int n,d;
ll a[MAXN];
ll only_front[MAXN] ,only_back[MAXN];
//ll d[MAXN];
void solve(){
	n=read(),d=read();
	for (int i=1;i<=n;i++) only_front[i]=1,only_back[i]=1;
	
	for (int i=1;i<=n;i++) a[i]=read();
	if(n>=2&&a[2]-a[1]<=d) only_front[2]=2; 
	for (int i=3;i<n;i++) {
		if(a[i]-a[i-1]<=d&&a[i]-a[i-2]>d) only_front[i]+=only_front[i-1];
	}
	
	if(n>=2&&a[n]-a[n-1]<=d) only_back[n-1]=2;
	for (int i=n-2;i>1;i--){
		if(a[i+1]-a[i]<=d&&a[i+2]-a[i]>d) only_back[i]+=only_back[i+1];
	}
	ll ans=0;
	for (int i=1;i+3<=n;i++){
		if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d) {
			ll exl=1,exr=1;
			for (int l=i-1;l>=1;l--) {
				if(a[i+1]-a[l]>d&&a[i]-a[l]<=d) exl+=only_front[l];
			}
			for (int r=i+4;r<=n;r++){
				if(a[r]-a[i+2]>d&&a[r]-a[i+3]<=d) exr+=only_back[r];
			}
			ans+=exl*exr; 
		}
	}
	printf("%lld\n",ans);
		
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while (t--) solve();
	
	return 0;
}
