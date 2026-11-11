#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],r,pre[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i] = pre[i-1]+a[i];
    for(int l=1;l<=n;l++)
    {
        while(r<l&&a[l]*(l-r)-(pre[l]-pre[r])>m)r++;
        ans = max(ans,l-r);
    }
    cout<<ans<<endl;
    return 0;
}