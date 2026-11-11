#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long xmax=0;
long long a[200005];
long long n,m;
void f(long long ans,long long pos,long long des)
{
	if(des==m)
	{
		xmax=max(xmax,ans);
		return ;
	}
	
	for(int i=pos+1;i<=n;i++)
	{
		f(ans&a[i],i,des+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f(a[i],i,1);
	}
	cout<<xmax;
}
