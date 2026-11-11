#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000100],b,gg,uu[1000100],zz,oo;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		uu[i]=a[i];
	}
	sort(a+1,a+n+1);
	gg=m;
	ll xx;
	for(int i=1;i<=n;i++)
	{
		b=a[i];
		for(int j=1;j<=i;j++)
		{
			if(a[j]<b&&(gg!=0&&gg>=b-uu[j]))
			{
				gg-=b-uu[j];
				uu[j]=b;
				zz++;
				xx=j;
			}
		}
		for(int i=xx;i<=n;i++)
		{
			if(uu[i]==uu[i+1])
			{
				zz++;
			}
			else 
			{
				continue;
			}
		}
		if(zz<oo)
		{
			cout<<oo;
			return 0;
		}
		else oo=zz;
		for(int i=1;i<=n;i++)
		{
			uu[i]=a[i];
		}
		gg=m;
		zz=0;
	}
	return 0;
}
