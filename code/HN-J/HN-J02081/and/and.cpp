#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
const long N=210000;
long n,m,a[N];
string s[N];
string er(long q)
{
	string s1;
	char c1;
	while(q)
	{
		c1=q%2+'0';
		s1=c1+s1;
		q/=2;
	}
	return s1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=er(a[i]);
		//cout<<s[i]<<" ";
	}
	
	return 0;
}

