#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char b[200010];
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		if(b[l]!=b[r])
		{
			ans+=min(a[l],a[r]);
		}
		if(a[l]<a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(a[r]==a[l])
			{
				r--;
				l++;
			}
			else
			{
			a[l]-=a[r];
			r--;	
			}
			
		}
	}
	cout<<ans;
	return 0;
}

