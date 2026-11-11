#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
int n,m;
ll a[N],da[N],sum=0;
ll cnt[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        //cout<<sum<<endl;
    }
    sort(a+1,a+n+1);
    ll avg=int(1ll*sum/n),pos=lower_bound(a+1,a+n+1,avg)-a;
    //cout<<pos<<endl;
    //int x=pos;
    ll xx=0,ls=pos;
    while(a[ls]==a[ls+1]) ls++;
    //if(abs(a[pos]-avg)>=abs(a[pos-1]-avg)) x=pos-1;
    for (int i=pos;i>=1;i--)
    {
        da[i]=da[i+1]+(a[pos]-a[i]);
        if(da[i]>m)
        {
            xx=i+1;
            break;
        }
        else xx=i;
    }
    printf("%lld\n",ls-xx+1);
    return 0;
}
