#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N];
int s[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1,j=0;i<=n;i++)
    {
        while((i-j+1)*a[i]-(s[i]-s[j-1])>m) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}