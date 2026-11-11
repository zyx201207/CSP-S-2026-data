#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
using namespace std;
struct dd
{
	int num;
	char k;
}a[200000+10];
int t;
long long n,ans;
int berf(int i)
{
	int cnt=1;
	while(1)
	{
		if(a[cnt].num<i)
		{
			i-=a[cnt].num;
			cnt++;
		}
		else
			return a[cnt].k;
	}
}
int berd(int i)
{
	int cnt=t;
	while(1)
	{
		if(a[cnt].num<i)
		{
			i-=a[cnt].num;
			cnt--;
		}
		else
			return a[cnt].k;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i].num>>a[i].k;
		n+=a[i].num;
	}
	for(int i=1;i<=n/2;i++)
		if(berf(i) != berd(i))
			ans++;
	cout<<ans;
	return 0;
}

