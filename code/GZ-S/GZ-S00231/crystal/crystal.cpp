//GZ-S00231 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
long long l,r,n,m,a[500005],o,ma=1,dp[500005],u,tp1,tp2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]!=i)tp1=1;	
    	a[i]+=1e12+1;
    	if(a[i]-a[i-1]!=a[i-1]-a[i-2])tp2=1;
	}			
	if(tp1==0||tp2==0)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+a[i];
		}
		l=1,r=1;
		u=1;
		while(l<=r&&r<=n)
		{
			ma=max(ma,u);
			if(o<=m)
			{
				r++;
				u++;
				o=a[r]*u-dp[r]+dp[l-1];
			}
			while(o>m)
			{
	
				l++;
				u--;
				o=a[r]*u-dp[r]+dp[l-1];
				if(r<n&&l==r)
				{
					o=0;
					u=1;
					l++;
					r++;
					break;
				}
			}
		}
		cout<<ma;	
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+a[i];
	}
	l=1,r=1;
	u=1;
	while(l<=r&&r<=n)
	{
		ma=max(ma,u);
		if(o<=m)
		{
			r++;
			u++;
			o=a[r]*u-dp[r]+dp[l-1];
		}
		while(o>m)
		{

			l++;
			u--;
			o=a[r]*u-dp[r]+dp[l-1];
			if(r<n&&l==r)
			{
				o=0;
				u=1;
				l++;
				r++;
				break;
			}
		}
	}
	cout<<ma;
	return 0;
}
