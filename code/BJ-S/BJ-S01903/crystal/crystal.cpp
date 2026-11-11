#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back

using namespace std;
typedef long long ll;;
typedef pair<int,int> pii;

const int N=5e5+233;
ll n,a[N],m,pre[N];
inline ll sol(int i)
{
    int ans=1,l=1,r=i,mid;
    while (l<=r)
    {
        mid=l+r>>1;
        if (mid*a[i]-(pre[i]-pre[i-mid])<=m) ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    ll ans=1;
    for (int i=1;i<=n;i++)
        ans=max(ans,sol(i));
    cout<<ans<<endl;

    return 0;
}


