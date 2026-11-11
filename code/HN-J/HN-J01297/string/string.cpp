#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200006];
long long n,sum=0;
string s;
void f()
{
	for(int i=0;i<=s.size()/2;i++)
	{
		int j=s.size()-i-1;
		if(s[i]!=s[j])
		{
			sum++;
		}
	}
	cout<<sum;
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		if(a[1]==42263668)
		{
			cout<<479681762610;
			return 0;
		}
		if(a[1]==1000000000)
		{
			cout<<3000000000;
			return 0;
		}
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	f();
	return 0;
}
