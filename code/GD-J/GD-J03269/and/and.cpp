#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,i,j,k,a[200005],b[100005],c,d;
long long ii,jj,xx,yy,zz;
char s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		c=a[i];
		k=0;
		while(1)
		{
			d=c%2;
			c=c/2;
			k++;
			b[k]=d;
			if(c==0)
			{
				break;
			}
		}
		for(j=k;j>=1;j--)
		{
			if(b[j]=='0')
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		if(x>xx)
		{
			xx=m;
			z=a[i];
		}
		if(y>yy)
		{
			yy=m;
			zz=a[i];
		}
	}
	if(z!=0)
	{
		cout<<z;
	}
	else
	{
		cout<<zz;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
