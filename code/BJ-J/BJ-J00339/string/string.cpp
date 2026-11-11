#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,num=0;
	string s;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		long long op;
		char c;
		scanf("%lld",&op);
		num+=op;
		cin>>c;
		for(int i=1;i<=op;i++)
		{
			s+=c;
		}
	}
	long long t=s.size();
	string s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<t/2;i++)
	{
		if(s[i]!=s1[i]) ans++;
	}
	cout<<ans;
	return 0;
}
