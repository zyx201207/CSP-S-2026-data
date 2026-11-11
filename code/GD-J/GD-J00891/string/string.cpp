#include<bits/stdc++.h>
using namespace std;
int n,a[200005],sum,cnt;
char b[200005],c[200005];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i]>>b[i];
		for(int j=sum+1;j<=sum+a[i];j++)
		{
			c[j]=b[i];
		}
		sum+=a[i];
	}
	int v;
	if(sum%2==0)
	{
		v=sum/2;
	}
	if(sum%2!=0)
	{
		v=(sum-1)/2;
	}
	for(int i=1;i<=v;i++)
	{
		if(c[i]!=c[sum-i+1])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
