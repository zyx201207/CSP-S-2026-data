#include <bits/stdc++.h>
using namespace std;
void pass()
{
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],st,nd,cnt=0;
	char c[n];
	string s="";
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	st=0,nd=s.size()-1;
	while(st<=nd)
	{
		if(s[st]!=s[nd])
		{
			cnt++;
		}
		st++;
		nd--;
	}
	cout<<cnt;
	return 0;
}

