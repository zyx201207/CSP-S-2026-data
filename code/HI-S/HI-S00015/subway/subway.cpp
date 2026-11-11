#include<bits/stdc++.h>
using namespace std;
int n,a[200005]={0},m,j=1,s[2]={0},c[200005];long long sum=0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++)
	{
		char c1;
		cin>>a[i]>>c1;
		c[i]=c1;
	}
	while(j<m)
	{
		if(c[j]!=c[m])
		{
			if(s[1]==0)
			{
				sum+=min(a[j],a[m]);
				if(a[j]<=a[m])
				{
					s[0]=2;
					s[1]=a[m]-a[j];
					j++;
				}
				if(a[m]<=a[j])
				{
					s[0]=1;
					s[1]=a[j]-a[m];
					m--;
				}
			}
			else
			{
				if(s[0]==1)
				{
					sum+=min(s[1],a[m]);
					if(s[1]<=a[m])
					{
						s[0]=2;
						s[1]=a[m]-s[1];
						j++;
					}
					if(a[m]<=s[1])
					{
						s[0]=1;
						s[1]=s[1]-a[m];
						m--;
					}
				}	
			}
		}
		else
		{
			int b;
			b=min(a[j],a[m]);
			if(a[j]<=a[m])
			{
				s[0]=2;
				s[1]=a[m]-a[j];
				j++;
			}
			if(a[m]<=a[j]);
			{
				s[0]=1;
				s[1]=a[j]-a[m];
				m--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
