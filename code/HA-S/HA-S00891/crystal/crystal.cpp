#include<bits/stdc++.h>
#define fileio(name) (freopen(name".in","r",stdin),freopen(name".out","w",stdout))
#define MAXN 500005
#define ll long long
using namespace std;
template<class T>inline void read(T& x){
	int f=1;char k=getchar();x=0;
	for(;k<'0'||k>'9';k=getchar())if(k=='-')f=-1;
	for(;'0'<=k&&k<='9';k=getchar())x=x*10+k-'0';
	x*=f;
}
ll n,m,a[MAXN],sum[MAXN];
int l,r,len,ans=0;
int main(){
	fileio("crystal");
	read(n),read(m);
	for(int i=1;i<=n;++i){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	l=1,r=1,len=1;
	while(r<=n){
		r++;
		while(a[r]*(r-l)-(sum[r-1]-sum[l-1])>m)l++;
		len=r-l+1;
		ans=max(ans,len);
	}
	printf("%d",ans);
	return 0;
}
