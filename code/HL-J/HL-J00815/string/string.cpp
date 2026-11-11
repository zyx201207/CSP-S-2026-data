#include <bits/stdc++.h>
using namespace std;
int num(string s){
	int cnt=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]==s[s.size()-i])
		{
			cnt+=0;
		}
		else
		{
			s[i]=s[s.size()-i];
			cnt+=1;
		}
	}
	return cnt;
}
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	s=' ';
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
	}
	cout<<num(s);
	return 0;
	
}