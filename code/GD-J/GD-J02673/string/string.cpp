#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x;
		cin>>c;
		for(int i=1;i<=x;i++)
		{
			s+=c;
		}
	}
	int a=s.size();
	bool f=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[a-i-1])
		{
			f=0;
			break;
		}
	}
	if(f)
	{
		cout<<0;
	}
	return 0;
}
