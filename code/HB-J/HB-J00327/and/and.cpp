#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int an(int x,int y)
{
	int aa[33],bb[33];
	for(int i=0;i<33;i++)
		aa[i]=0,bb[i]=0;
	int k1=0,k2=0;
	while(x>0)
	{
		aa[k1]=(x%2);
		x-=aa[k1];
		x/=2;
		k1++;
	}
	while(y>0)
	{
		bb[k2]=(y%2);
		y-=bb[k2];
		y/=2;
		k2++;
	}
	int k3=max(k1,k2),bbb;
	for(int i=k3;i>=0;i--)
	{
		if(aa[i]==1||bb[i]==1)
		bbb+=pow(2,i);
	}
	return bbb;		
}		
int main()
{
	int ans=-1;
	cin >> n >> m;
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++)
	cin >> a[i];
	if(n==m)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		ans=an(ans,a[i]);
	}	
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		ans=max(ans,a[i]);
	}	
	else if(m==2)
	{
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,an(a[i],a[j]));
			}	
	}	
	cout << ans;
	return 0;
}
