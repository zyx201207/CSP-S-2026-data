#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[1000001];
int b[1000001][101],ans[101];
void er(int e,int x)
{
	int i=0,i1;
	int y[100001];
	while(x>0)
	{
		y[++i]=x%2;
		x/=2;
	}
	i1=i;
	for(int j=1;j<=b[1][0];j++)
	{
		b[e][j]=0;
	}
	for(int j=i;j>=1;j--)
	{
		b[e][b[1][0]-i1+1]=y[j];
		i1--;
	}
}
int cf(int x)
{
	int y=1;
	for(int i=1;i<=x;i++)
	{
		y*=2;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x;
	x=a[n];
	int i=0,i1=0;
	int y[100001];
	while(x>0)
	{
		y[++i]=x%2;
		x/=2;
	}
	for(int j=i;j>=1;j--)
	{
		b[1][++i1]=y[j];
	}
	b[1][0]=i1;
	for(int i=n-1;i>n-m;i--)
	{
		er(n-i+1,a[i]);
	}
	for(int i=1;i<=b[1][0];i++)
	{
		int f=1;
		for(int j=2;j<=m;j++)
		{
			if(b[j-1][i]!=b[j][i])
			{
				f=0;
				break;
			}
		}
		if(f==1&&b[1][i]==1)
		{
			ans[i]=1;
		}
	}
	int num=0;
	for(int i=1;i<=b[1][0];i++)
	{
		int x=cf(b[1][0]-i);
		num=num+ans[i]*x;
	}
	cout<<num;
	return 0;
} 
