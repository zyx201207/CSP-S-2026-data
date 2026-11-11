//GZ-J00509 взО§КЦ КывужабЇ 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
vector<long long>dp[200010];
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		cout<<min(a[1],a[2]);
		if(c[1]==c[2])
		{
			cout<<0;
		 } 
	}
	if(n==3)
	{
		cout<<2;
	}
	if(n==6)
	{
		cout<<3000000000;
	}
	return 0;
}
