#include<bits/stdc++.h>
#define maxn 500050

using namespace std;
typedef long long ll;

ll a[maxn],b[maxn];
ll n,m;
ll res=1;

ll subtaskb()
{
    ll c=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        ll sum=1ll*(i-1)*(i)*c/2;
        if(sum>m) return i-1;
        else if(sum==m) return i;
    }
    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll c=a[2]-a[1];
    bool fb=false;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]!=c) fb=true;
    }
    if(!fb) cout<<subtaskb()<<'\n';
    else 
    {
        if(n<=6000)
        {
            for(int i=1;i<=n;i++)
            {
                ll now=m;
                ll ans=0;
                for(int j=1;j<=i;j++)
                {
                    b[j]=a[i]-a[j];
                }
                sort(b+1,b+i+1);
                for(int j=1;j<=i;j++)
                {
                    now-=b[j];
                    ans++;
                    if(now<0) break;
                }
                ans-=(now<0);
                res=max(res,ans);
            }
            cout<<res<<'\n';
        }
        else 
        {
            ll mx=-1e18;
            for(int i=1;i<=n;i++) mx=max(mx,a[i]);
            ll all=0;
            for(int i=1;i<=n;i++)
            {
                all+=mx-a[i];
            }
            if(all<=m) cout<<n<<'\n';
            else
            {
                for(int i=1;i<n;i++)
                {
                    ll ned=i*(a[i+1]-a[i]);
                    m-=ned;
                    if(m<0) {cout<<i<<'\n';return 0;}
                    else if(m==0) continue;
                }
            }
        }
    }
    return 0;
}