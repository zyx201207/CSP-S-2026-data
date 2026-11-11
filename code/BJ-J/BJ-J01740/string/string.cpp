#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,ans,sum;
struct node{
    ll len;
    char v;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].len>>a[i].v;
        sum+=a[i].len;
    }
    ll k=(sum+1)/2;
    if(sum%2==1)
    {
        k--;
    }
    ll j=n,en=0;
    for(ll i=1;i<=n;i++)
    {
        if(k<=0)
        {
            break;
        }
        ll p;
        if(a[i].len<=k)
        {
            p=a[i].len;
        }
        else
        {
            p=k;
        }
        k-=p;
        while(p>0)
        {
            if(en!=0)
            {
                if(p>=en)
                {
                    p-=en;
                    if(a[i].v!=a[j].v)
                    {
                        ans+=en;
                    }
                    en=0;
                    j--;
                }
                else
                {
                    en-=p;
                    if(a[i].v!=a[j].v)
                    {
                        ans+=p;
                    }
                    p=0;
                }
            }
            else
            {
                if(a[j].len<=p)
                {
                    p-=a[j].len;
                    if(a[i].v!=a[j].v)
                    {
                        ans+=a[j].len;
                    }
                    j--;
                }
                else
                {
                    if(a[i].v!=a[j].v)
                    {
                        ans+=p;
                    }
                    en=a[j].len-p;
                    p=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
