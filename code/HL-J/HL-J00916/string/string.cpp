#include<bits/stdc++.h>
using namespace std;
string zi;
long long sum,ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long s;
		char f;
		cin>>s>>f;
		for(long long j=1;j<=s;j++)
		{
			zi+=f;
		}
	}
	for(long long i=0;i<zi.length()/2;i++)
	{
		if(zi[i]!=zi[zi.length()-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}