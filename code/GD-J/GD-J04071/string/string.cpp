#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,a[MAXN];
char c[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n;
    long long ans{};
    while(l<r)
    {
        int d=min(a[l],a[r]);
        ans+=(c[l]!=c[r])*d;
        a[l]-=d,a[r]-=d;
        if(!a[l])l++;
        if(!a[r])r--;
    }
    cout<<ans;
    return 0;
}