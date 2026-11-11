#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a;
	char ch;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a>>ch;
		for(int j=1;j<=a;j++)
		{
			s+=ch;
		}
	}
	int cnt=0;
	n=s.size();
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
