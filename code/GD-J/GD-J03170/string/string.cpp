#include <bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int cnt=0;
	long long num=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		long long a1;
		char c1;
		cin >> a1 >> c1;
		num+=a1;
		if(c[i-1]==c1)
		{
			a[cnt]+=a1;
		}
		else
		{
			cnt++;
			a[cnt]=a1;
			c[cnt]=c1;
		}
	}
	
	if(cnt==1)
	{
		cout << 0;
		return 0;
	}
	num=num/2;
	
	for(int i=1;i<=cnt/2;i++)
	{
		if(c[i]==c[cnt-i+1])
		{
			if(a[i]>=a[cnt-i+1])
			{
				num-=a[cnt-i+1];
			}
			else
			{
				num-=a[i];
			}
		}
	}
	
	cout << num;
	return 0;
}
