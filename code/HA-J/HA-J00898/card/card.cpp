#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],t,b[500002],p[300005],r[300005];
bool g[300005];
int f(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		if(b[i]==x)
		{
			return i;
		}
	}
	return 0;
}
int f2(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		if(r[i]==x)
		{
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int d=1;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t;
		if(!f2(t,d-1))
		{
			r[d]=t;
			d++;
		}
	}
	int s=0;
	for(int q=1;q<=n;q++)
	{
		for(int i=1;i<=s;i++)
		{
			g[b[i]]=0;
			b[i]=0;
		}
		s=q;
		for(int i=s;i<=n;i++)
		{
			if(f(a[i],s-1))
			{
				for(int j=1;j<=s;j++)
				{
					b[j]=0;
				}
				b[1]=a[i];
				s=2;
			}
			else
			{
				b[s]=a[i];
				s++;
			}
		}
		for(int i=1;i<=s-1;i++)
		{
			if(g[b[i]]==0)
			{
				g[b[i]]=1;
				p[b[i]]+=1;
			}
		}
	}
	for(int i=2;i<=d;i++)
	{
		cout<<p[r[i]]<<' ';
	}
	return 0;
}
