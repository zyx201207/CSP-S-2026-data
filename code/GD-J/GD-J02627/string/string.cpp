#include<bits/stdc++.h>
using namespace std;
long long ma,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		sum+=x;
		ma=max(ma,x);
		while(x--)s+=c;
	}
	string c;
	c=s;
	reverse(c.begin(),c.end());
	if(s==c)
	{
		cout<<0;
		return 0;
	}
	cout<<sum-ma;
	return 0;
} 
