#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s+=c;
	}

	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
}
