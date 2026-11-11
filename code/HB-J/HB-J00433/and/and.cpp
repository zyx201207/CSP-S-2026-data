#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans;
void xz(ll val,ll s,ll pos){
    if(s==m){
        ans=max(ans,val);
        return;
    }
    for(int i=pos+1;i<=n;i++){
        if(s<=m) xz(val&a[i],s+1,i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
        }
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
    }
    else if(n<=20) xz(pow(2,30)-1,0,0);
    else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    cout<<ans;
    return 0;
}
