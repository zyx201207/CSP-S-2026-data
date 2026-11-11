#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n+1],b[n+1],c[n+1],sum=0,h=0,id,man=0;
	char s[n+1],s1[n+1],s2[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	sum/=2;
	sum++;
    man=0;
	for(int i=1;i<=n;i++)
	{
		h+=a[i];
		if(h>=sum)
		{
			b[i]=a[i]-(h-sum)-1;
			id=i;
			s1[i]=s[i];
			break;
		}
		else
		{
			b[i]=a[i];
			s1[i]=s[i];
		}
	}
	for(int i=id;i<=n;i++)
	{
		if(i==id)c[i]=b[i]+(h-sum)+1;
		else c[i]=a[i];
		s2[i]=s[i];
	}
	for(int i=1;i<id;i++)
	{
		for(int j=id;j<=n;j++)
		{
			if(s1[i]!=s2[j]&&c[j]>=b[i])
			{
				man+=c[j];
				c[j]-=b[i];
			}
			else 
			{
				if(s1[i]==s2[j])
				{
					if(b[i]>c[j])
					{
						man+=c[j];
						b[i]-=c[j];
					}
					else c[j]-=b[i];
				}
			}
		}
	}
	cout<<man;
}
