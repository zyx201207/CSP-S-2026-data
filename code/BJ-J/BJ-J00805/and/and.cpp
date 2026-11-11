#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],maxa,ans,is[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        is[i]=1;
    }
    ll x=1ll<<31;
    while(x>0)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(is[i] && a[i]&x) cnt++;
        if(cnt>=m)
        {
            ans+=x;
            for(int i=1;i<=n;i++)
            {
                is[i]=is[i]&&(a[i]&x);
            }
        }
        x=(x>>1);
    }
    cout<<ans<<endl;
    return 0;
}
