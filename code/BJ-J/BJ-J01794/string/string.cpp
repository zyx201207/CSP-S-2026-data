#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn=2e5+5;

struct Node
{
    ll cnt;
    char c;
}a[maxn];

ll n,sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].cnt;
        cin>>a[i].c;
        sum+=a[i].cnt;
    }
    ll mid=sum/2,ans=0;
    ll l=1,r=n;
    while(l<r)
    {
        ll sr=a[r].cnt,sl=a[l].cnt;
        if(sl>=sr)
        {
            while(sl>=sr&&(l<r))
            {
                if(a[l].c!=a[r].c) ans+=a[r].cnt;
                r--;
                sr+=a[r].cnt;
            }
            if(l==r)
            {
                break;
            }
            if(sr>sl)
            {
                int t=a[r].cnt;
                a[r].cnt=sr-a[l].cnt;
                if(a[r].c!=a[l].c) ans+=t-a[r].cnt;
            }
            l++;
        }
        else
        {
            while(sr>=sl&&(l<r))
            {
                if(a[l].c!=a[r].c) ans+=a[l].cnt;
                l++;
                sl+=a[l].cnt;
            }
            if(l==r)
            {
                break;
            }
            if(sl>sr)
            {
                int t=a[l].cnt;
                a[l].cnt=sl-a[r].cnt;
                if(a[l].c!=a[r].c) ans+=t-a[l].cnt;
            }
            r--;
        }
    }

    cout<<ans<<'\n';

    return 0;
}
