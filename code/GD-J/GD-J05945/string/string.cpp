#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,a[3][200010]={0},x,y;
void pp(int l,int r)
{
	if(x==y)
	{
		if(a[2][l]!=a[2][r])
		{
			ans+=x;	
		}
		if(l+1==r-1||r-l==1)
			{
				return;	
			}
			else
			{
				x=a[1][l+1];
				y=a[1][r-1];
				pp(l+1,r-1);	
			}		
	} 
	else
	{
	 if(x>y)
	{
		if(a[2][l]!=a[2][r])
		{
			ans+=y;	
		}
		if(l==r-1)
			{
				return;	
			}
			else
			{
				x-=y;
				y=a[1][r-1];
				pp(l,r-1);	
			}		
	}
	else
	{
		if(a[2][l]!=a[2][r])
		{
			ans+=x;	
		}
		if(l+1==r)
			{
				return;	
			}
			else
			{
				x=a[1][l+1];
				y=a[1][r];
				pp(l+1,r);	
			}	
	}
	}
}
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s;
	cin>>n;
	int m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[1][i];
		cin>>s;
		m=s;
		m-=96;
		a[2][i]=m;
	}
	x=a[1][1];
	y=a[1][n];
	pp(1,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
