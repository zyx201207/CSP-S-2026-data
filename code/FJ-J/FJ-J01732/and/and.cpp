#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool f=1;
long long ans,n,m,pmax,p2,sum,a[N],b[40],c[N],d[N][40];
void ff(long long x)
{
	long long t=0,y=x;
	while(x)
	{
		b[++t]+=x%2,p2=max(p2,t),d[y][t]=x%2;
		x/=2;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pmax=max(pmax,a[i]);
		ff(a[i]);
	}
	sum=n;
	for(int i=p2;i>=1;i--)
	{
		if(b[i]>=m)
		{
			ans+=pow(2,i-1);
			memset(b,0,sizeof(b));
			int s=0;
			if(f)
			{
				for(int j=1;j<=sum;j++)
				{
					if(d[a[j]][i])
					{
						c[++s]=a[j],ff(a[j]);
					}
					f=0;
				}
			}
			else
			{
				for(int j=1;j<=sum;j++)
					if(d[c[j]][i])
					{
						a[++s]=c[j],ff(c[j]);
					}
				f=1;
			}
			sum=s;
		}
	}
	cout<<ans;
	return 0;
}
