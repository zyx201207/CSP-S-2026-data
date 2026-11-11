#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
ll n,d;
ll a[2000010];
ll nxt[2000010],lst[2000010];
ll snxt[2000010],slst[2000010];
ll snxto[2000010],slsto[2000010];
ll ans;
ll solnxt(ll x,ll y,ll z)
{
    ll l=x,r=z,ret=x;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[mid]-a[x]<=y)
        {
            ret=max(ret,mid);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ret;
}
ll sollst(ll x,ll y,ll z)
{
    ll l=z,r=x,ret=x;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[x]-a[mid]<=y)
        {
            ret=min(ret,mid);
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        //cout<<d<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            //cout<<a[i]-a[i-1]<<endl;
        }
        nxt[n+1]=n;
        for(int i=n;i>=1;i--)
        {
            nxt[i]=solnxt(i,d,nxt[i+1]);
            //cout<<nxt[i]<<" ";
        }
        //cout<<endl;
        lst[0]=1;
        for(int i=1;i<=n;i++)
        {
            lst[i]=sollst(i,d,lst[i-1]);
            //cout<<lst[i]<<" ";
        }
        //cout<<endl;
        for(int i=n;i>=1;i--)
        {
            snxt[i]=1;
            if(lst[nxt[i]]==i&&nxt[i]!=i)
                snxt[i]+=snxt[nxt[i]];
            //cout<<snxt[i]<<" ";
            if(lst[i]!=i&&nxt[lst[i]]!=i)
                slsto[lst[i]]++;
        }
        //cout<<endl;
        for(int i=1;i<=n;i++)
        {
            slst[i]=1;
            if(nxt[lst[i]]==i&&lst[i]!=i)
                slst[i]+=slst[lst[i]];
            if(nxt[i]!=i&&lst[nxt[i]]!=i)
                snxto[nxt[i]]++;
            //cout<<slst[i]<<" ";
        }
        //cout<<endl;
        //for(int i=1;i<=n;i++)
            //cout<<slsto[i]<<" ";
        //cout<<endl;
        /*for(int i=1;i<=n;i++)
        {
            if(nxt[i]==i)
                continue;
            for(int j=i+1;j<=n;j++)
            {
                if(lst[j]>nxt[i])
                    break;
                if(nxt[i]==lst[j]+1&&lst[j]>i&&nxt[i]<j)
                    ans+=slst[i]*snxt[j];
                cout<<i<<" "<<nxt[i]<<" "<<j<<" "<<lst[j]<<" "<<ans<<endl;
            }
        }*/
        for(int i=1;i<=n;i++)
        {
            if(lst[i]<i-1&&nxt[i-1]>i)
                ans+=(slst[i]+snxto[i]-1)*(snxt[i-1]+slsto[i-1]-1);
            //cout<<i<<" "<<slst[i]<<" "<<snxt[i-1]<<" "<<ans<<endl;
        }
        /*for(int i=1;i<=n;i++)
        {
            if(nxt[i]-1>i)
                ans+=slst[i]*(slsto[nxt[i]-1]+snxt[nxt[i]-1]-1);
        }*/
        cout<<ans<<endl;
        for(int i=0;i<=n+1;i++)
        {
            nxt[i]=0;
            lst[i]=0;
            snxt[i]=0;
            slst[i]=0;
            snxt[i]=0;
            slsto[i]=0;
        }
        ans=0;
    }
    return 0;
}
