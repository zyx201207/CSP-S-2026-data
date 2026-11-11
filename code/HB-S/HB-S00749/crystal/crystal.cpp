#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pre[N];
inline bool check(int l,int r){
    int sum=pre[r]-pre[l-1];
    if(sum+m>=a[r]*(r-l+1))return true;
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int r=1,ans=0;
    for(int l=1;l<=n;l++){
        while(r<n&&check(l,r+1))r++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}