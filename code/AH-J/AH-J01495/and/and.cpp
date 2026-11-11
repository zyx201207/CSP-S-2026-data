#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],f[200010],maxn=0;
void GGB(int u,long long x)
{
	if(u==0)
	{
		maxn=max(maxn,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			GGB(u-1,x&a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)                
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		GGB(m-1,a[i]);
		f[i]=0;
	}
	cout<<maxn;
	return 0;
}
