#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,sum;
bool flag=0;
string s;
struct S
{
	long long x;
	char s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s;
		sum+=a[i].x;
		for(int j=1;j<=a[i].x;j++)
		{
			s+=a[i].s;
		}
	}
	sum--;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
