#include<bits/stdc++.h>
using namespace std;
int n,a[200005],maxx;
long long sum;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx>=sum-maxx)
	{
		cout<<sum-maxx;
		return 0;
	}
	sum=0;
	for(int i=1,j=n;i<j;)
	{
		if(c[i]!=c[j])
		{
			if(a[i]>=a[j])
			{
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}
			else 
			{
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else
		{
			if(a[i]>=a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else 
			{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}

