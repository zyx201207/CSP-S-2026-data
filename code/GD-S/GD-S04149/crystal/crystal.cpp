#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long s1=0,s2=0,l=1;
	for(int i=1;i<n;i++)
	{
		if(m>=(a[i+1]-a[i])*(i-l))
		{
			m-=(a[i+1]-a[i])*i;
			s1++;
		}
		else
		{
			while(l<=i)
			{
				m+=a[i]-a[l];
				l++;
				if(s1!=0)s1--;
				if(m>=(a[i+1]-a[i])*(i-l))
				{
					m-=(a[i+1]-a[i])*(i-l);
					s1++;
					break;
				}
			}
		}
		if(s1>s2)s2=s1;
	}
	if(s1>s2)s2=s1;
	cout<<s2;
	return 0;
}
