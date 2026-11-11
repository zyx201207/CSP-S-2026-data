#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,t,n;
ll d,a[2000010];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        if(c==11||c==12)
        {
            ll x=d/(a[2]-a[1])+1;
            if(x==1||x==2)cout << "0\n";
            else cout << max(0ll,(ll)n-(2*x-2)+1) << '\n';
            continue;
        }
        if(c==13||c==14)
        {
            int l=lower_bound(a+1,a+n+1,a[1]+d)-a;
            int r=lower_bound(a+1,a+n+1,a[n]-d)-a;
            cout << l << " " << r << endl;
            if(l<=r)cout << 0 << '\n';
            else if(l-r+1==2)cout << 1 << '\n';
            else if(l-r+1>2)cout << 2 << '\n';
            continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                int l=i,r=j;
                while(a[l+1]-a[i]<=d)l++;
                while(a[j]-a[r-1]<=d)r--;
                if(l-r+1==2)
                {
                    int ls=i,rs=j;
                    while(ls>=2&&a[ls+1]-a[ls-1]>d&&a[ls]-a[ls-1]<=d)ls--;
                    while(rs<=n-1&&a[rs+1]-a[rs-1]>d&&a[rs+1]-a[rs]<=d)rs++;
                    ans+=(i-ls+1)*(rs-j+1);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
