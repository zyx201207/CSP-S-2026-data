#include <bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0,cnt=0;
string c[100000005],b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=ans+1;j<=a[i]+ans;j++)
		 {
		 	c[j]=b[i];
		 }
		ans+=a[i];
	}
	if (ans%2==1)
	{
		for (int i=1;i<=(ans-1)/2;i++)
		{
			if (c[i]!=c[ans+1-i])
			{
				cnt++;
			}
		}
	}
	else
	{
		for (int i=1;i<=(ans-1)/2;i++)
		{
			if (c[i]!=c[ans+1-i])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0; 
 } 
