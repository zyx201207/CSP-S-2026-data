#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],sum[N];
void solveA(){
    int d=1,ans=1;
    while(m>=d&&ans+1<=n){
        m-=d;
        d++,ans++;
    }
    cout<<ans;
    return;
}
void solveB(int d){
    cout<<min(m/d+1,n);
    return;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int d=a[2]-a[1];
    bool ok=1,ok2=(a[1]==1);
    for(int i=2;i<=n;i++){
        if(a[i]!=i)ok2=0;
        if(a[i]-a[i-1]!=d){
            ok=0;
            break;
        }
    }
    if(ok2){
        solveA();
        return 0;
    }
    if(ok){
        solveB(d);
        return 0;
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=1,l=1,r=1;
    while(r<=n&&l<=r){
        while(r+1<=n&&(r-l+1)*a[r+1]-sum[r]+sum[l-1]<=m){
            r++;
            ans=max(ans,r-l+1);
        }
        l++;
    }
    cout<<ans;
    return 0;
}
