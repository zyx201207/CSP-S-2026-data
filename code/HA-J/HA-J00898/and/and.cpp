#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],t,l,k;
//int cf(int x,int y)
//{
//	int s=x;
//	if(y=0) return 1;
//	for(int i=2;i<=y;i++)
//	{
//		s*=x;
//	}
//	return s;
//}
//int f(int x,int y)
//{
//	int x1[32],jx=0,xs[32];
//	while(x>0)
//	{
//		jx++;
//		x1[jx]=x%2;
//		x/=2;
//	}
//	int g=1;
//	for(int i=jx;i>=1;i--)
//	{
//		xs[g]=x1[i];
//	}
//	int y1[32],jy=0,ys[32];
//	while(y>0)
//	{
//		jy++;
//		y1[jy]=y%2;
//		x/=2;
//	}
//	g=1;
//	for(int i=jy;i>=1;i--)
//	{
//		ys[g]=y1[i];
//	}
//	int z[32],j=min(jx,jy);
//	for(int i=1;i<=j;i++)
//	{
//		if(xs[i]==1&&ys[i]==1)
//		{
//			z[i]=1;
//		}
//		else
//		{
//			z[i]=0;
//		}
//	}
//	int o=j-1,c=0;
//	for(int i=1;i<=j;i--)
//	{
//		c*=10;
//		c+=cf(z[i],o);
//		o--;
//	}
//	return c;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t;
		if(l<t)
		{
			l=t;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			k=f(a[i],a[j]);
//			if(l<k)
//			{
//				l=k;
//			}
//		}
//	}
	cout<<l;
	return 0;
}
