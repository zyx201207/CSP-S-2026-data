#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],m,cr,d,ans,cl,a1[100010];
char b[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        m+=a[i];
        a1[i]=a[i];
        a[i]+=a[i-1];
    }
    d=n;
    for(ll i=1;i<=n;i++)
    {
        cl=m-a[i];
        cr=m-a[i-1];
        for(ll j=d;a[j]>cl;j--)
        {
            if(a[j]<cl)
            {
                break;
            }
            else
            {
                if(a[j]>cr)
                {
                    if(b[j]!=b[i])
                    {
                        ans+=cr-a[j-1];
                    }
                }
                else
                {
                    if(a[j]<=cr&&a[j-1]>=cl)
                    {
                        if(b[j]!=b[i])
                        {
                            ans+=a1[j];
                        }
                    }
                    else
                    {
                        if(b[j]!=b[i])
                        {
                            ans+=a[j]-cl;
                        }
                    }
                }
            }
            d=j;
        }
    }
    cout<<ans/2;
    return 0;
}
