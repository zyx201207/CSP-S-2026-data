#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt; 
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1,ff1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1 && a[i]!=a[i-1]) f=0;
		if(a[i]!=i) ff1=0;
	}
	if(f==1)
	{
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cnt=1;
	for(int i=2;i<=n;i++)
	{
		if(m-(a[1]-a[i])>=0)
		{
			m-=a[1]-a[i];
			cnt++;
		}
		else break;
	}
	cout<<cnt;
	return 0;
}
