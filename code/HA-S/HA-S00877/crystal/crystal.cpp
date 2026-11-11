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
const int N=5e5+5;
int n;
ll m,a[N],sum[N],zas;
#define mid ((l+r)>>1)
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++)a[i]=in();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ll l=1,r=i,ans=i;
		while(l<=r){
			//cout<<l<<" "<<r<<" "<<mid<<" "<<<<"\n";
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
				ans=min(ans,mid);
				r=mid-1;
			}else l=mid+1;
		}
		//cout<<i<<" "<<ans<<"\n";
		zas=max(zas,i-ans+1);
	}
	out(zas);
	return 0;
}
