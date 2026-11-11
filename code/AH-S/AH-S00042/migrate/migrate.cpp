#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000005,mod=998244353;
ll c,T,n,d,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==11||c==12)
        {
            ll t=d/(a[2]-a[1]);
            if(t<=1)cout<<"0\n";
            else cout<<max(n-2*t+1,0LL)<<"\n";
        }
    }
    return 0;
}
