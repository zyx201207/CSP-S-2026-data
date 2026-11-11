#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
char c;
string s;
long long ans; 
int main()
{
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}	
	}
	long long tt= s.length();
	for(int i=0;i<s.length()/2;i++)
	{
		tt--;
		if(s[i]!=s[tt])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
// Trick||Treat! 
