#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)	s=s+c;
	}
	long long sum=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i]) sum++;
	}
	cout<<sum;
	return 0;
}
