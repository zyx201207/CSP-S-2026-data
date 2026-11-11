#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=5e5+3;
typedef long long ll;
ll a[N],pre[N];
int main()
{
    // freopen(R"(/home/rdfz/code/problem/crystal/crystal3.in)","r",stdin);
    freopen("crystal.in","r",stdin);
    // freopen(R"(/home/rdfz/code/duipai/data.in)","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    ll maxa=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    sort(a+1,a+1+n);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+(maxa-a[i]);
        int l=1,r=i;
        while (l<r)
        {
            int mid=l+r>>1;
            ll cost=pre[i]-pre[mid-1]-(i-mid+1)*(maxa-a[i]);
            if (cost<=m)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}
