#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long func(long long x)
{
	string s;
	while(x>0)
	{
		s=s+(char)((x&1)+'0');
		x>>=1;
	}
	reverse(s.begin(),s.end());
	long long sum=0; 
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			sum++;
		}
	}
	return sum;
}
bool cmp(long long x,long long y)
{
	return func(x)>func(y);
}
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(long long i=2;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
