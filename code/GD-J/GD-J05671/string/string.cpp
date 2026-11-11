#include<bits/stdc++.h>
using namespace std;
const long long N=1000000009;
long long n;
char s[N];
//string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s[++t]=c;
		}
	}
	long long cnt1=0;
	for(int i=1;i<=t/2;i++)
	{
		if(s[i]!=s[t-i+1])cnt1++;
	}
	cout<<cnt1;
	
	return 0;
} 
