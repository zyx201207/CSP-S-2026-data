#include<bits/stdc++.h>
#define ll long long
#define N 2000006 
using namespace std;
ll c,T,n,d;
ll ans=0;
ll a[N],al[N],ar[N],f[N],g[N],list[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
		cin>>n>>d;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++)
        {
            ll l=1,r=i;
            while ((l<r))
            {
                ll mid=(l+r)/2;
                if(a[mid]+d<a[i])
                {
                    l=mid+1;
                }
                else
                    r=mid;
            }
            
            if(a[l]+d>=a[i])
            {
                al[i]=l;
            }
            l=1;r=i;
            while ((l<r))
            {
                ll mid=(l+r)/2;
                if(a[mid]-d>a[i])
                {
                    r=mid-1;
                }
                else
                    l=mid;
            }
            if(a[r]-d<=a[i])
            {
                ar[i]=r;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<=n;j++)
				f[j]=0;
            for(ll j=0;j<=n;j++)
				g[j]=0;
            for(ll j=0;j<=n;j++)
				list[j]=i;
            f[i]=0;
            g[i]=1;
            list[0]=i;
            for(ll j=i+1;j<=n;j++)
            {
                ll jl=max(al[j],i);
                if(jl==j)
                {
                    break;
                }
                f[j]=f[jl]+1;
                list[f[j]]=j;
                ll cur=g[list[f[jl]]]-g[jl-1];
                if(cur==2)
                {
                    ans++;
                }
                g[j]=g[j-1]+cur;
            }
        }
        cout<<ans<<"\n";
    }
}
