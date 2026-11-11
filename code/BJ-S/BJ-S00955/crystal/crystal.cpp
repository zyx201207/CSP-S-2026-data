#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],f[N];
bool cmp(int x,int y){
    return x>y;
}
void solve(){
    for(int i=1;i<=n;i++) f[i]=f[i-1]+a[1]-a[i];
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    // cout<<"\n";
    int maxn=0;
    for(int i=1;i<=n-maxn;i++){
        m+=(n-i)*a[i-1];
        maxn=max(maxn,upper_bound(f+1,f+n+1,m)-f-i);
        // for(int j=1;j<=n;j++) cout<<f[j]<<" ";
        // cout<<"\n";
    }
    cout<<maxn<<"\n";
    exit(0);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    bool flag=1;
    for(int i=3;i<=n;i++){
        if(a[i-2]-a[i-1]!=a[i-1]-a[i]) flag=0;
    }
    if(flag) solve();
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++) f[i]=f[i-1]+a[1]-a[i];
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    // cout<<"\n";
    int maxn=0;
    for(int i=1;i<=n-maxn;i++){
        maxn=max(maxn,upper_bound(f+1,f+n+1,m)-f-i);
        for(int j=i+1;j<=n;j++) f[j]-=(j-i)*(a[i]-a[i+1]);
        // for(int j=1;j<=n;j++) cout<<f[j]<<" ";
        // cout<<"\n";
    }
    cout<<maxn<<"\n";
    return 0;
}