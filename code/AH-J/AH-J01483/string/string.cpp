#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s={},c;
	long long n,a,cnt=0,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		cnt=cnt+a;
		for(long long i=0;i<a;i++)
		{
			s=s+c;
		}
	}
	string sum;
	sum=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<cnt;i++)
	{
		if(s[i]!=sum[i])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
