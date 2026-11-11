// GZ-S00148 遵义市第四中学 温岳城

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int N=500005;
ll a[N];
int main()
{
    // 45pts
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int n;ll m,sum=0;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int cnt=-1;
    for(int r=n;r>=1;r--)
    {
        sum=0;
        for(int l=r;l>=0;l--)
        {
            sum+=(a[r]-a[l]);
            if(sum>m) {cnt=max(cnt,r-l);break;}
        }
    }
    cout<<cnt;
    return 0;
    // BS
}
