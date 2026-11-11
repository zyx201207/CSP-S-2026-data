#include<bits/stdc++.h>
using namespace std;
int n,x,cnt;
char y;
string s,ss;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		while(x--)
			s+=y;
	}
	for(int i=s.size()-1;i>=0;i--)
		ss+=s[i];
	for(int i=0;i<s.size();i++)
		if(s[i]!=ss[i]) cnt++;
	cout<<cnt/2;
	return 0;
}
