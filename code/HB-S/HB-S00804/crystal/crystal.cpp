#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500050];
int ans=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int i;
    i=1;
    while(i<=n)
        {
            cin>>a[i];
            ++i;
        }
    sort(a+1,a+1+n);
    int p1,p2;
    p1=1,p2=1;
    int sum=0;
    while(p2<=n)
        {
            while(sum>m)
                {
                    sum-=a[p2]-a[p1];
                    ++p1;
                }
            ans=max(p2-p1+1,ans);
            ++p2;
            sum+=(a[p2]-a[p2-1])*(p2-p1);
        }
    cout<<ans;
    return 0;
}