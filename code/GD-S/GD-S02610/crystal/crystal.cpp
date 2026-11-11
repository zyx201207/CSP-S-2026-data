#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[50001],zhi,ge,sheng,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++)
	{
		zhi+=b[i]*i;
		if(zhi>m)
		{
			zhi-=b[i]*i;
			ge=i;
			i=n;
			sheng=m-zhi;
		}
	}
	long long hou=ge;
	for(int i=1;i<=n;i++)
	{
		if(sheng>=ge*(a[hou+1]-a[hou]))
		{
			ge+=1;
			hou+=1;
			sheng-=ge*(a[hou+1]-a[hou]);
		}
		else if(a[hou]-a[i]+sheng>=(ge-1)*(a[hou+1]-a[hou]))
		{
			hou+=1;
			sheng-=a[hou]-a[i]-(ge-1)*(a[hou+1]-a[hou]);
		}
		ans=max(ans,ge);
	}
	cout<<ans;
	return 0;
} 
//5 8
//-3 -1 2 2 7
