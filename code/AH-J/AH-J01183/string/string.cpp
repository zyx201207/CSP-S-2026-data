#include <iostream>
using namespace std;
long long c[200005],sum[200005];
char ch[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i] >> ch[i];
		sum[i]=sum[i-1]+c[i];
	}
	long long mid=(sum[n]+1)/2,x;
	for(int i=1;i<=n;i++)
	{
		if(sum[i]>=mid)
		{
			x=i;
			break;
		}
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<=r)
	{
		if(x==r)
		{
			for(int i=l;i<=n;i++)
			{
				if(ch[i]!=ch[r])
				{
					ans+=c[i];
				}
			}	
			cout << ans;
			return 0;
		}
		if(x==l)
		{
			for(int i=l;i<=n;i++)
			{
				if(ch[i]!=ch[l])
				{
					ans+=c[i];
				}
			}	
			cout << ans;
			return 0;
		}
		if(c[l]<c[r])
		{
			c[r]-=c[l];
			if(ch[l]!=ch[r])
			{
				ans+=c[l];
			}
			c[l]=0;
			l++;
		}
		else if(c[l]==c[r])
		{
			if(ch[l]!=ch[r])
			{
				ans+=c[l];
			}
			c[l]=0;
			c[r]=0;
			l++;
			r--;
		}
		else
		{
			c[l]-=c[r];
			if(ch[l]!=ch[r])
			{
				ans+=c[r];
			}
			c[r]=0;
			r--;
		}
	}
	cout << ans;
	return 0;
}






















































































































































































//感谢来自CCF的恩赐（划掉）部分分，至少100+100+70+0=270































//——————————————————————————————————————————————————————这是理论最高分————————————————————————————————————————————

































































































