#include<bits/stdc++.h>
using namespace std;
int l,a[200005];
long long t=0;
char c[200005];
string s;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>l;
for(int i=1;i<=l;i++)
{	
	for(int j=1;j<=a[i];j++)
	{
	s=s+c[i];
	}
}
for(int i=1;i<=s.size()/2;i++)
{
	if(s[i]!=s[s.size()-i+1]) 
	{
		s[i]=s[s.size()-i+1];
		t++;
	}
}
cout<<t;
	return 0;
} 
