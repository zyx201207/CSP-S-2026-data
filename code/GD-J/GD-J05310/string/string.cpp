#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++) s+=y;
	}
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()+1-i]) ans++;
	} 
	cout<<ans;
	return 0; 
 } 
