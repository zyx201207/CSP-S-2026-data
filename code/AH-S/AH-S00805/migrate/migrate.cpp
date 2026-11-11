#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll a[N];
ll abss(ll abc){
    if(abc>0)
        return abc;
    return -abc;
}
signed main(){
    freopen("migrate1.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n;
        ll m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        if(c==11||c==12)
        {
            long long diff=a[2]-a[1];
            if(n<=4||diff*2>m)
            {
                cout<<0<<'\n';
                continue;
            }
            else
            {
                ll ans;
                if(m/diff==2)
                    ans=n-3;
                else if(m/diff>2&&m/diff*2<n)
                    ans=n+1-m/diff*2;
                else
                    ans=0;
                cout<<ans<<'\n';
            }
        }
        else if(c==13||c==14)
        {
;
        }
        else
        {
            int ans=0;
            for(int l=1;l<n;l++)
            {
                for(int r=l+1;r<=n;r++)
                {
                    int anss=0;
                    for(int cnt=1;cnt<=n;cnt++)
                    {
                        if(cnt==l||cnt==r)
                            continue;
                        if(abss(a[l]-a[cnt])<=m&&abss(a[cnt]-a[r])<=m)
                            tot++;
                    }
                    if(tot==2)
                        ans++;
                }
            }
        cout<<ans<<'\n';
        }
    }
    return 0;
}

