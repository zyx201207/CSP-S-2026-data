#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0;
ll a[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll j=30;j>=0;j--)
    {
        ll p_ans=ans|(1<<j),cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if((a[i]&p_ans)==p_ans)cnt++;
        }
        // cout<<cnt<<' '<<m<<'\n';
        if(cnt>=m)ans=p_ans;
    }
    cout<<ans;

    return 0;
}