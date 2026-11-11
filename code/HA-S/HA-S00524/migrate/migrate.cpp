#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-')f=-1;ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }char c[23];int cnt=0;do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int N=2000005;
int n,a[N],r[N],l[N],c,T,d;
inline bool chk(int le,int ri){
	int now=1,L=le;
	if(r[le]>=ri)return 0;
	le=r[le];
	while(le<ri){
		int nxt=min(r[le],ri);
		if(nxt==le)return 0;
		now*=le-l[nxt]+1;
		if(now>2)return 0;
		le=nxt;
	}
	return now==2;
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++){ a[i]=read(); }
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]-a[i]<=d)j++;
			r[i]=j-1;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j&&a[i]-a[j]<=d)j--;
			l[i]=j+1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) ans+=chk(i,j);
		}
		write(ans);puts("");
	}
	return 0;
}
