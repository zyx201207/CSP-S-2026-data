#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],cnt[N],r=-1,l=1e15;
int n,m;
ll ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]+100001]++;
        if (r<a[i]+100001) r=a[i]+100001;
        if (l>a[i]+100001) l=a[i]+100001;
    }
    if (r-l<=300)
    {
        for (int i=l;i<=r;i++)
        {
            ll msum=0;
            ll num=0;
            for (int j=i;j>=l;j--)
            {
                ll tmp=i-j;
                ll sum=cnt[j]*tmp;
                msum+=sum;
                num+=cnt[j];
                if (msum>m)
                {
                    ll cha=msum-m;
                    ll x=ceil(cha*1.0/tmp*1.0);
                    num-=x;
                    break;
                }
            }
            if (ans<num) ans=num;
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        ll sum=0;
        ll num=0;
        for (int j=i;j>=1;j--)
        {
            ll tmp=a[i]-a[j];
            sum+=tmp;
            if (sum<=m)
                num++;
            else break;
        }
        if (ans<num) ans=num;
    }
    cout<<ans;
    return 0;
}