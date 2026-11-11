#include<iostream>
#include<string>
using namespace std;
string s;
long long cnt=0,n,a;
char b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a;j++)
		s=s+b;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
