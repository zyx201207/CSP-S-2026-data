#include<bits/stdc++.h>
using namespace std;
long long cnt;
string s;
char c;
int n;
long long x;
int a[1000000]={},b[1000000]={},h[10000000]={};
void f()
{
	int l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(long long j=1;j<=x;j++)
		{
			s=s+c;
		}
	}
	f();
	cout<<cnt;
	return 0;
}
