#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string b;
		cin>>a>>b; 
		for(int j=0;j<a;j++)
		{
			s+=b;
		}
	}
	int cnt=0;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
 } 
