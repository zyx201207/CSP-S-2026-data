#include<bits/stdc++.h>
using namespace std;
#define int long long
struct gg
{
    int dat,l,r,add;
}p[2000005];
int a[500005],b[500005];
void up(int num){p[num].dat=p[num*2].dat+p[num*2+1].dat; return; }
void down(int num)
{
    if(p[num].add)
    {
        p[num*2].dat+=(p[num*2].r-p[num*2].l+1)*p[num].add;
        p[num*2+1].dat+=(p[num*2+1].r-p[num*2+1].l+1)*p[num].add;
        p[num*2].add+=p[num].add;
        p[num*2+1].add+=p[num].add;
        p[num].add=0;
    }
    return ;
}
void build(int num,int l,int r)
{
    p[num].l=l;
    p[num].r=r;
    if(l==r) {p[num].dat=b[l]; return;}
    int mid=(l+r)/2;
    build(num*2,l,mid);
    build(num*2+1,mid+1,r);
    up(num);
    return;
}
void change(int num,int l,int r,int x)
{
    if(p[num].l>=l&&p[num].r<=r)
    {
        p[num].dat+=(p[num].r-p[num].l+1)*x;
        p[num].add+=x;
        return;
    }
    down(num);
    int mid=(p[num].l+p[num].r)/2;
    if(l<=mid) change(num*2,l,r,x);
    if(r>mid) change(num*2+1,l,r,x);
    up(num);
    return ;
}
int qr(int num,int l,int r)
{
    if(p[num].l>=l&&p[num].r<=r)
    {
        return p[num].dat;
    }
    down(num);
    int mid=(p[num].l+p[num].r)/2,sum=0;
    if(l<=mid) sum+=qr(num*2,l,r);
    if(r>mid) sum+=qr(num*2+1,l,r);
    return sum;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=a[n]-a[i];
    build(1,1,n);
    for(int i=n;i>1;i--)
    {
        if(a[i]==a[i+1]) continue;
        change(1,1,i,(b[i+1]-b[i]));
        int l=1,r=i-1,mid,as=1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(qr(1,mid,i)<=m)
            {
                as=i-mid+1;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,as);
    }
    cout<<ans;
    return 0;
}