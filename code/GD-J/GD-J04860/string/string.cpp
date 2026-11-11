#include<bits/stdc++.h>
using namespace std;
long long n,t,l,a;
char c;
string s=" ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a--)
		{
			s=s+c;
		} 
	}
	l=s.size()-1;
	for(long long i=1;i<=l/2;i++)
	{
		if(s[i]!=s[l+1-i]) 
		{
			t++;
		}
	} 
	cout<<t;
	return 0;
}
