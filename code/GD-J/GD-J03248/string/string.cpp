#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s="";
	int n;
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	int l=0,r=s.size()-1;
	bool z=1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			z=0;
			break;
		}
		l++;
		r--;
	}
	if(z==1)
	{
		cout<<"0";
	}
	return 0;
}
