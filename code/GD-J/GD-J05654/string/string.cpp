#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,q=0;
	char b[N];
	string s;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			s+=b[i];
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1]) q++;
	}
	cout<<q;
	return 0;
}
