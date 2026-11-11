#include<bits/stdc++.h>
using namespace std;
#define int long long
int un(int x,int y)
{
	int a[35]={0},cnt=0,z=0;
    while((x+y)>0)
    {
    	cnt++;
    	if((x%2+y%2)==1)
    	{
    		a[cnt]=0;
    	} 
    	else a[cnt]=1;
    	x/=2;
    	y/=2;
    }
	for(int i=cnt;i>=1;i--)
	{
		z*=2;
		z+=a[i];
	}
	return z;
}
bool cmp(int x,int y)
{
	return x>y;
}
int a[200008];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-1]&a[i];
	}
	int maxn=-2;
	for(int i=1;i<=n-m+1;i++)
	{
		maxn=max(maxn,un(a[i],a[i+m-1]));
	}
	cout<<maxn;
	return 0;
}
