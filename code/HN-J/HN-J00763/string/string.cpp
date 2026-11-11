#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char s,x[1005];
	cin>>n;
	long long mj=1;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>s;
		for(int j=1;j<=a;j++)
		{
			x[mj]=s;
			mj++;
		}
		sum+=a;
	}
	long long num=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(x[i]==x[sum-i+1])
		{
			continue;
		}
		else
		{
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
