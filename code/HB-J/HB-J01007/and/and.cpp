#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long ans=0,n,m,a[200005],dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    For(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        ans=a[1];
        For(i,2,n)ans=(ans&a[i]);
        cout<<ans;
        return 0;
    }
    if(m==2){
        ans=0;
        For(i,1,n)For(j,i+1,n)ans=max(ans,a[i]&a[j]);
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        ans=a[2];
        For(i,3,n)ans=(ans&a[i]);
        cout<<ans;
        return 0;
    }
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--)ans=ans&a[i];
    cout<<ans;
    return 0;
}
