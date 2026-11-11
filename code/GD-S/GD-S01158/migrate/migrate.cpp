#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5,inf=1e15;
int a[maxn],n,d,mx[maxn],c[maxn],b[maxn];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int id_,T;
	cin>>id_>>T;
	if(id_==11 || id_==12)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n==1)
			{
				cout<<0<<'\n';
				continue;
			}
			int t=a[2]-a[1];
			d/=t;
			if(d==1)
			{
				cout<<0<<'\n';
				continue;
			}
			int s=0;
			for(int i=1;i<=n;i++)
			{
				if(i+d+d-1<=n)s++;
			}
			cout<<s<<'\n';
		}
		return 0;
	}
	if(id_==13 || id_==14)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int r=1;
			for(int i=1;i<=n;i++)
			{
				while(r<n && a[r+1]-a[i]<=d)r++;	
				mx[i]=r;
			}
			int t=mx[1],s=0;
			for(int i=1;i<=n;i++)
			{
				r=mx[mx[i]];
				if(r<i+2)continue;
				if(mx[mx[i]-2]>=r || (mx[mx[i]-1]>=r && mx[i]-1!=t && mx[i]!=t))continue;
				s++;
			}
			cout<<s<<'\n';
		}
		return 0;
	}
	if(id_<=10)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int r=1;
			for(int i=1;i<=n;i++)
			{
				while(r<n && a[r+1]-a[i]<=d)r++;	
				mx[i]=r;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)c[j]=inf,b[j]=0;
				c[i]=0,b[i]=1;
				for(int j=i;j<=n;j++)
				{
					for(int l=j+1;l<=mx[j];l++)
					{
						if(c[l]>c[j]+1)
						{
							c[l]=c[j]+1;
							b[l]=b[j];
						}
						else if(c[l]==c[j]+1)b[l]+=b[j];
					}
				}
				for(int j=i;j<=n;j++)if(b[j]==2)ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
luoguid:zengzidi
*/
