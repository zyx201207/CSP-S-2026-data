#include<bits/stdc++.h>
using namespace std;using ll=long long;
ll rd(ll x=0,char c=getchar()){int f=1;while(!isdigit(c))f=(c^'-'?1:-1),c=getchar();while(isdigit(c))x=x*10+(c^48),c=getchar();return x*f;}
const int N=5e5+5;
int n,ans;
ll a[N],m,sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i++){
		sm[i]=sm[i-1]+a[i];
		while(a[i]*(i-j+1)-(sm[i]-sm[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
