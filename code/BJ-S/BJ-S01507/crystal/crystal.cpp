#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m,a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;
    ll sum=a[1];
    int ans=0;
    while(r<=n)
    {
        sum+=a[++r];
        while(a[r]*(r-l+1)-sum>m)
        {
            sum-=a[l++];
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
