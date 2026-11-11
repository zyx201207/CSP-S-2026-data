#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-')f=-1;ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }char c[23];int cnt=0;do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int N=500005;
int n,a[N],m,s[N];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){a[i]=read();}
	sort(a+1,a+n+1);for(int i=1;i<=n;i++){ s[i]=s[i-1]+a[i]; }
	int ans=1;
	for(int i=2;i<=n;i++){
		while(ans<i&&a[i]*(ans+1)-(s[i]-s[i-ans-1])<=m)ans++;
	}
	write(ans);
	return 0;
}
