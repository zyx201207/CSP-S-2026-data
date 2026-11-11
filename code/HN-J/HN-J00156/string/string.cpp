#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,sum=0,cnt=0,h=0;
	cin>>n;
	string x;
	for(int i=1;i<=n;i++)
	{
		long long a;
		string b;
		cin >> a >> b;
		for(int j=1;j<=a;j++)
		{
			x+=b;
		}
		sum+=a;
	}
	for(int i=1;i<=sum;i++)
	{
		if(x[i]==x[sum-i])
		{
			h++;
		}
		else
		{
			x[sum-i]==x[i];
			cnt++;
		}
	}
	cout << cnt-1;
	return 0;
}
