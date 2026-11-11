#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000001;
int c,T,x[N],f[N],g[N],ans,n,d,L[N],R[N];
void calc(int z)
{
	for(int i=z;i<=n;i++)
	{
		f[i]=1e9;
		g[i]=0;
	}
	f[z]=0,g[z]=1;
	int res=z;
	for(int i=z+1;i<=n;i++)
	{
		while(res<=i)
		{
			if(x[i]-x[res]>d)
			{
				res++;
			}
			else
			{
				break;
			}
		}
		if(res>i)
		{
			return;
		}
		f[i]=f[res]+1;
		g[i]=g[res];
		if(res<i-1)
		{
			if(f[res+1]==f[res])
			{
				g[i]+=g[res+1];
			}
		}
		if(res<i-2)
		{
			if(f[res+2]==f[res])
			{
				g[i]+=g[res+2];
			}
		}
		g[i]=min(g[i],3ll);
		if(g[i]==2)
		{
			ans++;
		}
	}
	return;
}
void solveA()
{
	int p,z=x[2]-x[1];
	for(int i=1;i<=n;i++)
	{
		if(x[i]-x[1]<=d)
		{
			p=i-1;
		}
	}
	for(int i=p*2;i<=n;i++)
	{
		if(p>1)
		{
			ans++;
		}
	}
	return;
}
void solveB()
{
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,res=i;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if((x[mid]-x[i])<=d)
			{
				res=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		R[i]=res;
		l=1,r=i,res=i;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if((x[i]-x[mid])<=d)
			{
				res=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1; 
			}
		}
		L[i]=res;
	}
	for(int i=1;i<=n;i++)
	{
		int l=R[i]+1,r=n,res1=R[i]+1,res2=n;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if(R[i]-L[mid]+1>=2)
			{
				res1=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		if(R[i]-L[res1]+1!=2)
		{
			continue;
		}
		l=R[i]+1,r=n;
		while(l<=r)
		{
			int mid=((l+r)>>1);
			if(R[i]-L[mid]+1<=2)
			{
				res2=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans+=(res1-res2+1);
	}
	return;
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==1)
	{
		cout<<"0\n";
		return;
	}
	ans=0;
	if(c>10||c<1)
	{
		if(c==13||c==14)
		{
			solveB();
		}
		else
		{
			solveA();
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			calc(i);
		}
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
