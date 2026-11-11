#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[200005],m,ans;
bool cmp(long a,long b)
{
	return a>b;
}
int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=n;i++)ans=(ans&a[i]); 
}
