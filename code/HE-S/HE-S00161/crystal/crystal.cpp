#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=1;
	}
	if(f)
	{
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int cha=0,sum=1;
			for(int j=i-1;j>=1;j--)
			{
				cha+=a[i]-a[j];
				if(cha>m) break;
				sum++;
			}
			ans=max(ans,sum);
		}
		printf("%lld",ans);
	}
	else
	{
		int tmp=a[2]-a[1];
		int ans=0,need=0;
		for(int i=1;i<=n;i++)
		{
			need+=(i-1)*tmp;
			if(need>m) break;
			ans++;
		}
		printf("%lld",ans);
	}
	return 0;
}
//Oct31==Dec25?
//密码？所以说今天是圣诞节吗？
//CCF数据能不能waterful一点啊
