#include<bits/stdc++.h>
using namespace std;
string s;
char k;
long long n,a;
int num;
int main()
{
	freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>k;
		for(long long j=0;j<a;j++)
		{
			s+=k;
		}
	}
	for(long long i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()+1-i])
		{
			num++;
			s[i]=s[s.size()+1-i];
		}
	}
	cout<<num;
	return 0;
}
//ber
//good luck ^_^
