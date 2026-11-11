#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,a;
char c;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a)
		{
			s=s+c;
			a--;
		}
	}
	long long cnt=0;
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;	
} 
