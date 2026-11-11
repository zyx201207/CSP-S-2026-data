#include<bits/stdc++.h>
using namespace std;
long long a[200100];
char b[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	long long sum=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			sum++;
		}
	}
	int k=n,l=1;
	while(k>l)
	{
		int m=max(a[l],a[k]);
		if(a[l]==a[k])
		{
			if(b[l]!=b[k])
			{
				cnt+=a[l];
				a[l]=a[k]=0;
			}
			l++,k--;
		}
		else if(a[l]==m)
		{
			if(b[l]!=b[k])
			{
				cnt+=a[l]-a[k];
				a[l]-=a[k];
			} 
			k--;
		}
		else
		{
			if(b[l]!=b[k])
			{
				cnt+=a[k]-a[l];
				a[k]-=a[l];
			}
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
