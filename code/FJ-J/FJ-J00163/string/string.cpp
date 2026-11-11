#include <bits/stdc++.h>
using namespace std;
int n;
long long a,ans;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
	}
	long long ch=s.size()/2-1;
	long long ch1=s.size();
	for(long long i=0;i<=ch;i++)
	{
		if(s[i]!=s[ch1-i-1])
		    ans++;
	}
	cout<<ans;
	return 0;
}
