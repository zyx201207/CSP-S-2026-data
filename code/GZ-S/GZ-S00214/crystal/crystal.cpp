//GZ-S00214 遵义四中 安睿峰
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],sum[500010],l=1,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-l+1)-sum[i]+sum[l-1]>m&&l<=i)  l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
