#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<int> a(500005);
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(&a[1],&a[n+1]);
    int maxn=-1E18;
    for(int l=1,r=1,sum=0;r<=n;)
    {
        if(sum<=m)
        {
            sum+=(a[r+1]-a[r])*(r-l+1);
            r++;
        }
        while(sum>m)
        {
            sum-=a[r]-a[l];
            l++;
        }
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}