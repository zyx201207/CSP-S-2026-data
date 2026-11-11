#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define mkp make_pair
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
#define repn(i,a,b,g) for(LL i=a;i<b;i+=g)
using namespace std;
LL c,n,d,a[2000010],f[2000010],g[2000010],s[2000010];
LL q[2000010],L,R;
void sol()
{
	cin>>n>>d;
	rep(i,1,n,1)
	{
		cin>>a[i];
	}
	LL su=0;
	/*
	repn(l,1,n,1)
	{
		memset(f,0x3f,sizeof(f));
		memset(g,0,sizeof(g));
		f[l]=0;
		g[l]=1;
		rep(r,l+1,n,1)
		{
			repn(i,l,r,1)
			{
				if(a[r]-a[i]<=d)
				{
					if(f[r]>f[i]+1)
					{
						f[r]=f[i]+1;
						g[r]=0;
					}
					if(f[r]==f[i]+1)
					{
						g[r]+=g[i];
					}
				}
			}
//			if(n==10&&d==3&&a[1]==-1000000000000000000)
//			{
//				cout<<l<<' '<<r<<':'<<f[r]<<','<<g[r]<<endl;
//			}
			if(g[r]==2)
			{
//				cout<<l<<' '<<r<<endl;
				su++;
			}
		}
	}
	*/
	repn(l,1,n,1)
	{
		f[l]=0;
		g[l]=1;
		rep(i,1,n,1)s[i]=0;
		s[0]=1;
		L=1;
		R=0;
		q[++R]=l;
		rep(r,l+1,n,1)
		{
			while(L<=R&&a[r]-a[q[L]]>d)
			{
				s[f[q[L]]]-=g[q[L]];
				L++;
			}
			if(L>R)break;
			f[r]=f[q[L]]+1;
			g[r]=s[f[q[L]]];
			s[f[r]]+=g[r];
			while(L<=R&&f[r]<f[q[R]])
			{
				s[f[q[R]]]-=g[q[R]];
				R--;
			}
			q[++R]=r;
//			if(n==10&&d==3&&a[1]==-1000000000000000000)
//			{
//				cout<<l<<' '<<r<<':'<<f[r]<<','<<g[r]<<endl;
//			}
			if(g[r]==2)
			{
//				cout<<l<<' '<<r<<endl;
				su++;
			}
		}
	}
	cout<<su<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL T;
	cin>>c>>T;
	while(T--)sol();
	return 0;
}
/*
50pts
*/
