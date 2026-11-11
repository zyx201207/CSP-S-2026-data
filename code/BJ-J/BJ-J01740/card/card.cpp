#include<bits/stdc++.h>
#define ls (i<<1)
#define rs (i<<1)|1
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,flag=1;
ll a[N],ans[N];
ll q[N],k[N];
struct node{
    ll sum,lazy;
}tr[N<<2];
void pushup(ll i)
{
    tr[i].sum=tr[ls].sum+tr[rs].sum;
    return ;
}
void pushdown(ll i,ll l,ll r,ll mid)
{
    tr[ls].lazy+=tr[i].lazy;
    tr[rs].lazy+=tr[i].lazy;
    tr[ls].sum+=(mid-l+1)*tr[i].lazy;
    tr[rs].sum+=(r-mid)*tr[i].lazy;
    tr[i].lazy=0;
    return ;
}
void init(ll i,ll l,ll r)
{
    tr[i].sum=tr[i].lazy=0;
    if(l==r)
    {
        return ;
    }
    ll mid=(l+r)>>1;
    init(ls,l,mid);
    init(rs,mid+1,r);
    return ;
}
void update(ll i,ll l,ll r,ll xl,ll xr,ll x)
{
    if(r<xl||l>xr)
    {
        return ;
    }
    if(l>=xl&&r<=xr)
    {
        tr[i].lazy+=x;
        tr[i].sum+=(r-l+1)*x;
        return ;
    }
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);
    update(ls,l,mid,xl,xr,x);
    update(rs,mid+1,r,xl,xr,x);
    pushup(i);
    return ;
}
ll query(ll i,ll l,ll r,ll xx)
{
    if(l==r)
    {
        return tr[i].sum;
    }
    ll mid=(l+r)>>1;
    pushdown(i,l,r,mid);
    if(mid>xx)
    {
        return query(ls,l,mid,xx);
    }
    else
    {
        return query(rs,mid+1,r,xx);
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1&&a[i]<a[i-1])
        {
            flag=0;
        }
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    else if(m==2)
    {
        ll t=a[n],cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(a[i]!=t)
            {
                cnt++;
            }
        }
        if(t==1)
        {
            cout<<n<<" "<<cnt;
        }
        else
        {
            cout<<cnt<<" "<<n;
        }
        return 0;
    }
    else if(flag==1)
    {
        for(ll i=1;i<=n;i++)
        {
            ans[a[i]]=i;
        }
        for(ll i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            q[j]=0;
            k[j]=0;
        }
        init(1,1,n);
        for(ll j=i;j<=n;j++)
        {
            q[j]=k[a[j]];
            k[a[j]]=j;
            ll w=q[j];
            while(w!=0&&query(1,1,n,w)>=1)
            {
                w=q[w];
            }
            if(w!=0)
            {
                update(1,1,n,w,j-1,1);
            }
        }
        for(ll j=i;j<=n;j++)
        {
            if(query(1,1,n,j)==0)
            {
                ans[a[j]]++;
            }
        }
    }
    for(ll i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
