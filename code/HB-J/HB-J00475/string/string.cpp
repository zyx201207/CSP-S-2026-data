#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
	}
	int k1=1,k2=n;
	int s1=a[1],s2=a[n];
	unsigned long long ans=0;
	while(k1<k2)
	{
		if(c[k1]!=c[k2])
		{
			if(s1>s2)
			{
				ans+=s2;
				s1-=s2;
				k2--;
				s2=a[k2];
			}
			else if(s2>s1)
			{
				ans+=s1;
				s2-=s1;
				k1++;
				s1=a[k1];
			}
			else
			{
				ans+=s1;
				k1++;
				k2--;
				s1=a[k1];
				s2=a[k2];
			}
		}
		else
		{
			if(s1>s2)
			{
				s1-=s2;
				k2--;
				s2=a[k2];
			}
			else if(s2>s1)
			{
				s2-=s1;
				k1++;
				s1=a[k1];
			}
			else
			{
				k1++;
				k2--;
				s1=a[k1];
				s2=a[k2];
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
