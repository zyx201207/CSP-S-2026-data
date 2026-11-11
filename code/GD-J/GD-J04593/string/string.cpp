#include<bits/stdc++.h>
using namespace std;
long long ans,a[200005];
int n;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>b[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(b[l]==b[r])
		{
			if(a[l]==a[r]) l++,r--;
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else 
			{
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]==a[r])
			{
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r])
			{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else
			{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
