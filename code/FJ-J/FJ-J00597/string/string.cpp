#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0;
	cin>>n;
	string s;
	s+=' ';
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	for(int i=1;i<=(s.size()-1)/2;i++)
	{
		if(s[i]!=s[s.size()-i])
		{
			cnt++;
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
