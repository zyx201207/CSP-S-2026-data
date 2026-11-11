#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define ff(x) for(ll i=he[x],y;i;i=e[i].ne)
const ll N=1e6+5;
ll f[N],a[N],n,d,g[N],ans,c,_,gc;
void S()
{
	ans=0;
	cin>>n>>d;
	fo(i,1,n)cin>>a[i];
	if(c==11||c==12)
	{
		gc=a[2]-a[1];
		if(d<2*gc)cout<<0<<endl;
		else
		{
			fd(i,n,2)
			{
				if(i*gc<=d&&d<(i+1)*gc)
				{
					cout<<max(n-i*2+1,0ll)<<endl;
					break;
				}
			}
		}
		return;
	}
	fo(i,1,n)
	{
		fo(j,i+1,n)
		{
			f[j]=1e18;
			g[j]=0;
		}
		f[i]=0;
		g[i]=1;
		fo(j,i+1,n)
		{
			fd(k,j-1,i)if(a[j]-a[k]<=d)
			{
				if(f[k]+1<f[j])
				{
					f[j]=f[k]+1;
					g[j]=g[k];
				}
				else if(f[k]+1==f[j])g[j]+=g[k];
			}
			else break;
		}
		fo(j,i+1,n)if(g[j]==2)ans++;
//		fo(j,1,n)cout<<f[j]<<" ";cout<<endl;
//		fo(j,1,n)cout<<g[j]<<" ";cout<<endl;cout<<endl;
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>_;
	while(_--)S();
}
