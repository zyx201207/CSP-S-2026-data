#include <bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001]; 
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for (int i=1;i<=n/2;i++)
	{
		if (i+1==n-i+1&&c[i]==c[n-i+1])
			continue;
		if (a[i]==a[n-i+1]&&c[i]==c[n-i+1])
			continue;
		if (i+1==n-i+1)
			ans+=min(a[i],a[n-i+1]);
		else
		{
			long long t=0,p1=a[i],p2=a[n-i+1];
			if (a[i]>a[n-i+1])
			{
				t=a[i]-a[n-i+1];
				a[n-i]-=t;
				a[n-i+1]=a[i];
				if (c[n-i]==c[n-i+1]&&c[n-i+1]==c[i])
					ans+=0;
				else if (c[n-i]==c[i])
					ans+=p2;
				else
					ans+=t+p2;
			}
			else if (a[i]<a[n-i+1])
			{
				t=a[n-i+1]-a[i];
				a[i+1]-=t;
				a[i]=a[n-i+1];
				if (c[i+1]==c[i]&&c[n-i+1]==c[i])
					ans+=0;
				else if (c[i+1]==c[n-i+1])
					ans+=p1;
				else
					ans+=t+p1;
			}
			else 
				ans+=p1;
		}
	}
	printf("%lld",ans);
}
