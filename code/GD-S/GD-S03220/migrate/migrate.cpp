#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100,M=505;
long long C,T,n,m,k,a[N],s;
int p[N];
struct jg
{
	int x,y;	
}f[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>C>>T;
	if(C==11||C==12)
	{
		for(;T--;)
		{
			s=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			k=n+1;
			for(int j=2;j<=n;j++)
			{
				if(a[j]-a[1]<=m)
				{
					k=j-1;
				}
				else
				{
					break;
				}
			}
			if(k>1)
				s=max(0ll,n-2*k+1);
			cout<<s<<"\n";
		}
		return 0;
	}
	for(;T--;)
	{
		s=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			f[i]={0,1};
			int l=1,r=0;
			p[++r]=i;
			for(int j=i+1;j<=n;j++)
			{
				for(;l<=r&&a[p[l]]+m<a[j];l++){}
				if(l>r)
				{
					break;
				}
				f[j]=f[p[l]];
				f[j].x++;
				for(int i=l+1;i<=r&&f[p[i]].x==f[p[l]].x;i++)
				{
					f[j].y+=f[p[i]].y;
					if(f[j].y>2)
					{
						break;
					}
				}
				//cout<<i<<' '<<j<<' '<<f[j].x<<' '<<f[j].y<<"\n";
				s+=(f[j].y==2);
				for(;l<=r&&f[p[r]].x>f[j].x;r--){}
				p[++r]=j;
			}
		}
		cout<<s<<"\n";
	}
}
