#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void dd(ll &x){
	x=0;
	char ch=getchar();int ff=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0',ch=getchar();
	}
	x*=ff;
}
const int N=5e5+5;
ll n,a[N],sum[N],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	dd(n),dd(m);
	for(int i=1;i<=n;++i) dd(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	int l=1,ans=0;
	for(int r=1;r<=n;++r){
		while(l<=r&&1ll*a[r]*(r-l+1)-(sum[r]-sum[l-1])>m){
			++l;
		}
		ans=max(r-l+1,ans);
	}
	printf("%d\n",ans);
} 
