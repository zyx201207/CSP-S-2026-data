#include <iostream>
#include <algorithm>
#define LL long long
#define N 500005
using namespace std;

int n;
LL m, a[N];
LL s[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; ++i)
    {
        s[i]=s[i-1]+a[i];
    }
    int ans=-1;
    for(int l=1, r=1; r<=n; ++r)
    {
        while(l<r && a[r]*(r-l)-(s[r-1]-s[l-1])>m)
        {
            ++l;
        }
        if(a[r]*(r-l)-(s[r-1]-s[l-1])<=m)
        {
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
