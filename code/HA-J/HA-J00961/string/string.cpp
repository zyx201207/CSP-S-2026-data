#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	int n,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
	    {
	    	s+=c[i];
	    }
	}
	int len=s.length()/2;
	int sum=0;
	for(int i=1;i<=len;i++)
	{
		if(s[i-1]!=s[s.length()-i])
		sum++;
	}
	cout<<sum;
	return 0;
}
