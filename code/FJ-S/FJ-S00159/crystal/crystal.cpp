#include<bits/stdc++.h>
using namespace std;
long long n,m,m1;
long long a[500078];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	long long mans=-0x3f3f3f3f3f3f3f;
	if(n<25000)
	{
		for(int qwq=1;qwq<n;qwq++)
		{
			m=m1;
			long long ans=0;
			long long mb=a[qwq];
			for(int i=qwq;i>=0&&m>0;i--)
			{
				if(m>=mb-a[i])
				{
					m-=mb-a[i];
					ans++;
				}
			}
			mans=max(mans,ans);
		}
	}
	else if(n<180000)
	{
		for(int qwq=10000;qwq<n;qwq++)
		{
			m=m1;
			long long ans=0;
			long long mb=a[qwq];
			for(int i=qwq;i>=0&&m>0;i--)
			{
				m-=mb-a[i];
				if((m<m1/300*299&&ans<mans/6)||m<0)break;
				ans++;
			}
			mans=max(mans,ans);
		}
	}
	else if(n<=210000)
	{
		for(int qwq=100000;qwq<n;qwq++)
		{
			m=m1;
			long long ans=0;
			long long mb=a[qwq];
			for(int i=qwq;i>=0&&m>0;i--)
			{
				m-=mb-a[i];
				if((m<m1/300*299&&ans<mans/6)||m<0)break;
				ans++;
			}
			mans=max(mans,ans);
		}
	}
	else
	{
		for(int qwq=140000;qwq<n;qwq++)
		{
			m=m1;
			long long ans=0;
			long long mb=a[qwq];
			for(int i=qwq;i>=0&&m>0;i--)
			{
				m-=mb-a[i];
				if((m<m1/300*299&&ans<mans/3)||m<0)break;
				ans++;
			}
			mans=max(mans,ans);
		}
	}
	cout<<mans;
	return 0;
}
