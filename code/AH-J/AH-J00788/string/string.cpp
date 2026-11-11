#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s1;
	int n,m,t=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>c;
		for(int j=1;j<=m;j++) s=s+c;
	}
	s1=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i]) t++;
	}
	cout<<t/2;
}
