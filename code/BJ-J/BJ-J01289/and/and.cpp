#include <bits/stdc++.h>
using namespace std;

long long n,m,maxs=-2e9,k,sum;
string s[200005];
struct node
{
	int x,y;
}a[200005];
int cmp(node A,node B)
{
	if(A.y!=B.y)
	{
		return A.y>B.y;
	}
	return A.x>B.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		if(a[i].x>maxs)
		{
			maxs=a[i].x;
			k=i;
		}
		long long t=a[i].x;
		while(t)
		{
			s[i]+=char(int('0')+t%2);
			t/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long t=1;
		long long z=s[i].size()-1;
		for(int j=0;j<=z;j++)
		{
			if(s[i][j]==s[k][j]&&s[k][j]=='1')
			{
				a[i].y+=t;
			}
			t*=10;
		}
	}
	sort(a+1,a+n+1,cmp);
	long long p=s[1].size()/2;
	for(int i=1;i<=p;i++)
	{
		long long t=s[1][i-1];
		s[1][i-1]=s[1][n-i+2];
		s[1][n-i+2]=t;
	}
	for(int i=2;i<=m;i++)
	{
		long long d=s[i].size()/2;
		for(int j=1;j<=d;j++)
		{
			int t=s[i][j-1];
			s[i][j-1]=s[i][n-j+2];
			s[i][n-j+2]=t;
		}
		long long t=10,c=1,q=1;
		long long u=s[k].size();
		for(int j=0;j<=u;j++)
		{
			if((a[i].y%t/c==a[i-1].y%t/c)&&(a[i-1].y%t/c==1))
			{
				sum+=q;
			}
			t*=10;
			c*=10;
			q*=2;
		}
	}
	cout<<sum;
	return 0;
}
