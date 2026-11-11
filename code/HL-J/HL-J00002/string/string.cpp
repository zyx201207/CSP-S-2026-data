#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,b,s_i=0,ans=0;
	char c;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>b>>c;
		for(int j=1; j<=b; j++)
		{
			s[s_i]=c;
			s_i++;
			
		}
		
	}
	cout<<s_i<<endl;
	int ts_i=0;
	for(int i=s_i-1; i>=0; i--)
	{
		if(s[i]!=s[ts_i])
		{
			ans++;
		}
			
		ts_i++;
	}
	cout<<ans/2;
	return 0;
}
