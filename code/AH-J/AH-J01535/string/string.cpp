#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u;
		char t;
		cin>>u>>t;
		for(int j=1;j<=u;j++)
		{
			a+=t;
		}
	}
	long long l=a.size();
	for(long long i=1;i<=l/2;i++)
	{
		if(a[i]!=a[l+1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
