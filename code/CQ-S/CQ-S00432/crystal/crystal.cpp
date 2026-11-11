#include<bits/stdc++.h>
using namespace std;
namespace RST
{
    int n;
    long long m;
    long long a[500005],s[500005];
    bool check(int id)
    {
        for(int i=id;i<=n;i++)
        {
            if(1ll*a[i]*id-(s[i]-s[i-id])<=m)
            {
                return true;
            }
        }
        return false;
    }
    void solve()
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+a[i];
        }
        int l=1,r=n;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans;
        return ;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)
    {
        RST::solve();
    }
    return 0;
}//g++ -o crystal.exe crystal.cpp -lm -O2 -std=c++14 -Wall -Wl,--stack=1000000000
//crystal.exe < ..\crystal\crystal1.in