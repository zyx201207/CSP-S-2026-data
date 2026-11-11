#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ma;
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		sum[i]=sum[i-1]+a[i]-a[i-1];
	int now=0;
	for(int i=1,j=1;j<=n;)
	{
		int k=j-i+1;
		if(now<=m) ma=max(ma,k),now+=(a[j+1]-a[j])*k,j++;
		else now=now-(a[j]-a[i]),i++;
	}
	printf("%lld",ma);
	return 0;
}
