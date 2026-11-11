#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8;
ll a[500007];
ll b[500007];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll x,lx;
    for(ll i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    if(m>=N)
    {
        ll ca=abs(b[2]-b[1]);
        ll can=m/ca;
        int j=0;
        for(ll i=1;;i++)
        {
            j+=i;
            if(can<j)
            {
                cout<<min(i,n);
                return 0;
            }
        }
    }
    sort(b+1,b+1+n);
    /*for(ll i=2;i<=n;i++)
    {
        a[i]=b[i]-b[i-1];
    }*/
    ll sum=0,maxx=0;
    for(ll i=2;i<=n;i++)
    {
        sum=0;
        for(ll j=i;;j--)
        {
            sum+=b[i]-b[j];
            if(sum>m||j<1)
            {
                maxx=max(maxx,i-j);
                //cout<<j<<" "<<i<<endl;
                break;
            }
        }
    }
    cout<<maxx;
    return 0;
}
