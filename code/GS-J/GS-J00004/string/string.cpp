#include <bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		string x;
		long long y;
		cin>>y>>x;
		for(long long j=1;j<=y;j++)
		{
			a+=x;
		}
	}
	long long i=0,j=a.size()-1;
	long long ans=0;
	while(i!=j)
	{
		if(a[i]!=a[j])
		{
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}
