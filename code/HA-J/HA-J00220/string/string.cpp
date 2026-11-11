#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum;
	vector<char> l;
	char c;
	cin>>n;
	sum=0;
	for (int i=0;i<n;i++)
	{
		cin>>a>>c;
		for (int j=0;j<a;j++)
		{
			l.push_back(c);
		}
	}
	sum=l.size();
	long long ans=0;
	for (int i=0;i<(sum/2);i++)
	{
		if (l[i]!=l[sum-i-1])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
