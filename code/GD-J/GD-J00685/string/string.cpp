#include<iostream>
#include<cstdio>
using namespace std;
long long n,cnt,ans;string s;
struct node
{
	long long a;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		cnt+=a[i].a;
		for(long long j=1;j<=a[i].a;j++)
		{
			s+=a[i].c;
		}
	}
	for(long long i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[cnt-i-1])
		{
			ans++;
		}
	 } 
	 cout<<ans;
} 
