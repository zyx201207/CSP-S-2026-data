#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long
#define frp freopen
#define fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts> 
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
	T res=0,f=1;char c;
	for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
	while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}
int n,ans;
ll m,a[maxn];
int main(){
	int i;
	fio("crystal.in","crystal.out");
	n=read(),m=read<ll>();
	for(i=1;i<=n;++i)a[i]=read<ll>();
	sort(a+1,a+n+1);
	ll s=0;
	int r=1,l=1;
	for(;r<=n;++r){
		s-=a[r];
		while(l<=r&&s+(r-l+1ll)*a[r]>m)s+=a[l],++l;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
