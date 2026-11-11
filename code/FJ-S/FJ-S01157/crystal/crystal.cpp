#include<bits/stdc++.h>
constexpr int rSiz=1<<21;
char rBuf[rSiz],*p1=rBuf,*p2=rBuf;
#define gc() (p1==p2&&(p2=(p1=rBuf)+fread(rBuf,1,rSiz,stdin),p1==p2)?EOF:*p1++)
template<class T>void rd(T&x){
	char ch=gc();bool o=0;
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')o=1;
	for(x=0;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	if(o)x=-x;
}
constexpr int _=5e5+5;
int n,ans;
long long m,a[_],b[_];
bool chk(int l,int r){return b[r]-b[l-1]+m>=a[r]*(r-l+1);}
#define fio(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
int main(){
	fio("crystal");
	rd(n),rd(m);
	for(int i=1;i<=n;++i)rd(a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(int i=1,j=1;i<=n;++i){
		for(;!chk(j,i);++j);
		ans=std::max(ans,i-j+1);
	}
	printf("%d\n",ans);
}
// 15:24 15:29