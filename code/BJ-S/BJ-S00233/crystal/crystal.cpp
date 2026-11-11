#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1,maxn=0,sum=0;
    while(1)
    {
        if(sum<=m)
        {
            sum+=(r-l+1)*(a[r+1]-a[r]);
            r++;
            maxn=max(maxn,r-l);
            if(r>n) break;
        }
        else
        {
            sum-=a[r]-a[l++];
        }
    }
    cout<<maxn<<endl;
    return 0;
}
