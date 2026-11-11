#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char c[200010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n,sum1=0,sum2=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	sum1=a[1],sum2=a[n];
	if(c[1]!=c[n])ans=min(sum1,sum2);
	while(l<r)
	{
		if(sum2<sum1)
		{
			r--;
			if(c[r]!=c[l])
			{
				if(sum2+a[r]<=sum1)ans+=a[r];
				else ans+=sum1-sum2;
			}
			sum2+=a[r];
		}
		else
		{
			l++;
			if(c[r]!=c[l])
			{
				if(sum1+a[l]<=sum2)ans+=a[l];
				else ans+=sum2-sum1;
			}
			sum1+=a[l];
		}
	}
	cout<<ans;
	return 0;
}
