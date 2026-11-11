#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
long long n,m,a[maxn],cnt,ans;
vector<int> x,y;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=29,l=1,r=n;i>=0;i--)
    {
        cnt=0;
        for(int j=l;j<=r;j++)
        if(a[j]&1<<i)cnt++,a[j]-=1<<i,x.push_back(a[j]);
        else y.push_back(a[j]);
        for(int j=l;j<=r;j++)
        {
            if(!x.empty())a[j]=x.back(),x.pop_back();
            else a[j]=y.back(),y.pop_back();
        }
        if(cnt>=m)ans+=1<<i,r=l+cnt-1;
    }
    cout<<ans;
    return 0;
}