#include <bits/stdc++.h> 
using namespace std;
int n;
long long num=1,cnt=0,sum=0;
string b[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		int c;
		cin>>a>>c;
		for(int j=num;j<=num+a-1;j++)
		{
			b[j]=c;
		}
		sum+=a;
		num=a+1;
	}
	for(int i=0;i<=sum/2;i++)
	{
		if(b[i+1]==b[sum-i])
		{
			continue;
		}
		else
		{
			cnt++;
		}
	}
	if(cnt==0)
	{
		cout<<"0";
	}
	else
	{
		cout<<cnt;
	}
	return 0;
}
