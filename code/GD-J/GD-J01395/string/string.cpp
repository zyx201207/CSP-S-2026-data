#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    char c='0';
    ll len=0,l=0,r=0;
}a[200005],nd;
int n,tot;
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>nd.len>>nd.c;
        if(nd.c==a[tot].c) a[tot].len+=nd.len;
        else
        {
            a[++tot].c=nd.c;
            a[tot].len=nd.len;
        }
    }
    ll l=1,r=tot;
    for(int i=1;i<=tot;i++)
    {
        a[i].l=a[i-1].r+1;
        a[i].r=a[i].l+a[i].len-1;
    }
    while(l<r)
    {
        if(a[l].c==a[r].c)
        {
            if(a[l].len>a[r].len)
            {
                a[l].l+=a[r].len;
                a[l].len-=a[r].len;
                r--;
                if(a[l].l>a[l].r) l++;
            }
            else
            {
                a[r].r-=a[l].len;
                a[r].len-=a[l].len;
                l++;
                if(a[r].l>a[r].r) r--;
            }
            continue;
        }
        if(a[l].len>=a[r].len)
        {
            ans+=a[r].len;
            a[l].l+=a[r].len;
            a[l].len-=a[r].len;
            r--;
            if(a[l].l>a[l].r) l++;
        }
        else
        {
            ans+=a[l].len;
            a[r].r-=a[l].len;
            a[r].len-=a[l].len;
            l++;
            if(a[r].l>a[r].r) r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
