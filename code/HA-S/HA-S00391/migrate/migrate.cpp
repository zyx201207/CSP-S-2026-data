#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int r=0,w=1;char c=getchar();
	while(c<'0'||c>'9') w=(c=='-')?(-1):(w),c=getchar();
	while(c>='0'&&c<='9') r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*w;
}const int N=2e6+5;
ll n,d,x[N],cf[N],pre[N],dp[5005][5005],len[N];
void Meow(){
	n=read(),d=read();
	bool xza=1,xzb=0,xzc=0;
	for(int i=1;i<=n;i++) x[i]=read();
//	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+x[1];
//	for(int i=1;i<=n;i++){
//		int l=1,r=i-1,mid;
//		while(l<=r){
//			mid=((r-l)>>1)+l;
//			if(pre[i]-pre[i-mid]<=d) l=mid+1;
//			else r=mid-1;
//		}len[i]=r;
//	}
	for(int i=3;i<=n;i++) if(x[i]-x[i-1]!=x[i-1]-x[i-2]) xza=0;
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			xzb=1;
			break;
		}
	}if(x[n]-x[1]<=10*d) xzc=1;
	if(xza){
		ll cnt=d/(x[2]-x[1]);
		if(cnt>1){
			ll le=(cnt<<1);
			printf("%lld\n",max(n-le+1,0ll));
		}else{
			printf("0\n");
		}
	}else if(xzb){
		int lp=1,rp=n;
		while(x[n]-x[lp]>d)lp++;
		while(x[rp]-x[1]>d)rp--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int idk=read(),t=read();
	while(t--) Meow();
	return 0;
}
