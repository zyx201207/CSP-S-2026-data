//GZ-S00037,刘一萱，贵阳市第一中学 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,a[N],sum[N],ch[N],m,f[N],A,B,l,r;
ll sum1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ch[i]=a[i]-a[i-1];
	}
	l=1;
	for (int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-l)*ch[i];
		if (f[i]<=m){
			sum1=max(sum1,i-l+1);
		}
		else{
			for (int j=l;j<=i;j++){
				f[i]=f[i]-(a[i]-a[j]);
				l++;
				if(f[i]<=m){
					sum1=max(sum1,i-l+1);
					break;
				}
			}
		}
	}
	printf("%lld",sum1);
	return 0;
}
