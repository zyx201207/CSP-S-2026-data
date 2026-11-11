#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long v[105];
long long f[100005];
struct node
{
	long long x,i;	
} k[200005];
long long a[200005][35];
long long s[200005][35];
bool cmp(node x,node y)
{
	return x.x>y.x;
}
void insert(long long k,long long x)
{
	for(long long i=30;i>=0;i--)
	{
		long long c=(x>>i)&1;
		if(c==1)
		{
			v[i]++;
			s[k][30-i+1]=1;
		}
		s[k][30-i+1]+=s[k][30-i];
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>f[i];
		insert(i,f[i]);
	}
	long long l=0;
	for(long long i=1;i<=n;i++) k[i].i=i;
	for(long long i=30;i>=0;i--)
	{
		if(v[i]>=m)
		{
			for(long long x=1;x<=n;x++)
			{
				k[x].x+=s[x][30-i+1]-s[x][30-i];
			}
			sort(k+1,k+1+n,cmp);
			if(k[m].x>k[m+1].x)
			{
				long long ans=f[k[1].i];
				for(long long p=2;p<=m;p++)
				{
					ans&=f[k[p].i];
				}
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
} 
