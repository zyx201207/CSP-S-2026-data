#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010]={},pj=0,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pj+=a[i];
	}
	pj/=n;
	sort(a,a+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>pj)
		{
			if(m>(i-1)*(a[i]-pj))
			{
				m-=(i-1)*(a[i]-pj+1);
			}
			else if(a[i]==a[i-1])
			{
				ans++;
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(m-(pj-a[i])<0&&a[i]!=a[i-1])
			{
				break;
			}
			else if(a[i]==a[i-1])
			{
				ans++;
				continue;
			}
			m-=(pj-a[i]);
		}
		ans++;
	}
	cout<<ans;
}
