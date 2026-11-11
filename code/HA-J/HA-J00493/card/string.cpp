#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
long long a[N];
string s,c,ts,ns;
int n; 
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> s[i];
		for(int j=1;j<=a[i];j++)
		{
			c+=s[i];
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	int weigh=sum/2;
	if(sum%2==1)
	{
		for(int i=0;i<weigh;i++)
		{
			ts+=c[i];
		}
		for(int i=sum-1;i>weigh;i--)
		{
			ns+=c[i];
		}
		for(int i=0;i<weigh;i++)
		{
			if(ts[i]!=ns[i])
			{
				cnt++;
			}
		}
	}else
	{
		for(int i=0;i<weigh;i++)
		{
			ts+=c[i];
		}
		for(int i=sum-1;i>=weigh;i--)
		{
			ns+=c[i];
		}
		for(int i=0;i<weigh;i++)
		{
			if(ts[i]!=ns[i])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
