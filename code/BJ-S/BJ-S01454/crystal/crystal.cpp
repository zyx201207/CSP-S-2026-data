#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[N];
        long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i =n;i>=1;i--)
	{
		for(int j =1;j<=i;j++)
		{
			b[i]+=a[i]-a[j];
		}
		if(b[i]==m)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
