#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200005];
	char c[200005];
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int sum=0;
	for (int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
