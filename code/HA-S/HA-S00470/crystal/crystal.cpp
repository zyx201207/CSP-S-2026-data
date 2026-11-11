#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int ans[500005],f;int n;
bool cmp(long long x,long long y)
{
	return x>y;
}
bool tou_a()
{
	for(int i = 2;i<=n-1;i++)
	{
		if(a[i]-a[i+1]!=a[i-1]-a[i])
		return false;
	}
	f = a[1]-a[2];
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long s1 = m;
	if(tou_a())
	{
		int t = 1;
		for(int i = 2;i<=n;i++)
		{
			s1 = s1-f*(i-1);
			if(s1<0) break;
			t++;
		}
		cout<<t;
		return 0;
	}
	for(int i = 1;i<=n-1;i++)
	{
		long long s = m;
		ans[i] = 1;
			for(int j = i+1;j<=n;j++)
			{				
				s = s-(a[i]-a[j]);
				if(s<0)
					break;
				ans[i]++;
			}
			if(ans[i]==n-i+1)
			{
				cout<<ans[i];
				return 0;
			}
	}
	sort(ans+1,ans+n+1,cmp);
	cout<<ans[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
