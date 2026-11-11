#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;

int n,m,a[N],s[N];

bool check(int mid)
{
    for(int l=1;l+mid-1<=n;l++)
    {
        int r=l+mid-1;
        if(mid*a[r]-(s[r]-s[l-1])<=m)return 1;
    }return 0;
}


signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
    int l=1,r=n,res=-1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))
        {
            l=mid+1;
            res=mid;
        }
        else r=mid-1;
    }
    cout<<res<<"\n";
    

    return 0;
}