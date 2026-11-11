#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a,ans=0;
	cin>>n;
	string m,s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>m;
		for(int j=1;j<=a;j++)
		{
			s+=m;
		}
	}
	long long mid=s.size()/2;
	for(int i=0;i<mid;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			ans++;
		}
	}
	if(n%2==0)
	{
		cout<<ans;
	}
	else
	{
		cout<<ans+1;
	}
    return 0;
}
