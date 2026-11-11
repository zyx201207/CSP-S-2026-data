#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n,t,ans=0;
	char c;
	string s,x,y;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t>>c;
		for(int j=1;j<=t;j++)
		{
			s+=c;
		}
	}
	for(i=0;i<(long long)(s.size()/2);i++)
	{
		x+=s[i];
	}
	for(i=(long long)(s.size()/2+((s.size()%2==0)?0:1));i<(long long)(s.size());i++)
	{
		y+=s[i];
	}
	reverse(y.begin(),y.end());
	for(i=0;i<=(long long)(x.size());i++)
	{
		if(x[i]!=y[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
