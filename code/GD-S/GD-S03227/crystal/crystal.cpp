#include<bits/stdc++.h>
using namespace std;
long long a[514114],n,m,ans=0,cnt=0,i;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	n++;
	long long r=n-1,l=n-2;
	for(i=1;i<n;i++)scanf("%lld",&a[i]);
	a[0]=INT_MIN;
	sort(a+1,a+n);
	while(l>=0)
	{
		cnt+=a[r]-a[l];
		if(cnt>m||l==0)
		{
			ans=max(ans,r-l);
			cnt-=(r-l)*(a[r]-a[r-1]);
			r--;
		}
		l--;
	}
	cout<<ans;
	return 0;
}
