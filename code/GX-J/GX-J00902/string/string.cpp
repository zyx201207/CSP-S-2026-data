#include<bits/stdc++.h>
using namespace std;
long long n,k;
char a;
string s;
int huiwen(string a)
{
	int b=a.size(),cnt=0;
	for(int i=0;i<sqrt(b);i++)
	{
		if(a[i]!=a[b-i-1])
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
cin>>n;
for(long long  i=1;i<=n;i++)
{
	cin>>k>>a;
	for(long long  j=1;j<=k;j++)
	{
		s+=a;
	}
}
cout<<huiwen(s);
return 0;
}
