#include<bits/stdc++.h>
#include<string>
using namespace std;
int n;
long long a,cnt;
string s,c;
int main()
{
	freopen('string.in','r',stdin);
	freopen('string.out','w',stdout);
	cin>>n;
	s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	long long k=s.size();
	for(int i=0;i<k/2;i++)
	{
		if(s[i]!=s[k-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
} 
