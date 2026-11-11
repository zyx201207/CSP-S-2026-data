#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll n,m,a[N],sum[N],maxx=-1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sum[1]=a[1];
    for(int i=2;i<=n;i++) sum[i]=a[i-1]&a[i];
    for(int i=1;i<=n;i++)
    {
        maxx=max(sum[i+m-1]&sum[i],maxx);
    }
    cout<<maxx;
    return 0;
}
