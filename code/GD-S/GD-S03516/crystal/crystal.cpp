#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=0;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	sum[0]=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i]; 
	for(int i=1;i<=n;i++){
		if(m<abs(i*a[i]-sum[i])){
			ans=i-1;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
