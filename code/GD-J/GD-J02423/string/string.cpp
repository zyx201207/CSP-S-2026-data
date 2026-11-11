#include<iostream>
#include<cstdio>
using namespace std;
string l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		char d;
		cin>>d;
		for(int j=1;j<=x;j++)
		{
			s+=d;
		}
	}
	int len=s.size();
	int cnt=len-1;
	for(int i=0;i<len/2;i++)
	{
		l+=s[i];
		r+=s[cnt];
		cnt--;
	}
	int ans=0;
	for(int i=0;i<l.size();i++)
	{
		if(l[i]!=r[i]) ans++;
	 }
	  cout<<ans;
	return 0;
}
