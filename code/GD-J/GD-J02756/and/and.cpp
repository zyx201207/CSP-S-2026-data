#include <bits/stdc++.h> 
using namespace std;
const long long N=2*100000+100;
long long n,m,a[N],ans;
bool b[N];
void dg(long long x,long long w)
{
	if(w==0)
	{
		ans=max(ans,x);
		return;
	}
	if(x==1)
	{
		if(ans==1)return;
	}
	for(int i=1;i<=n;i++)
	{
		if(x&a[i]!=0&&b[i]==0)
		{
			b[i]=1;
			dg(x&a[i],w-1);
			b[i]=0;
		}
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
		b[i]=1;
		dg(a[i],m-1);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}
