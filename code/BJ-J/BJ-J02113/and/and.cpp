#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000009];
bool check(int t){
    int ans;
    ans=0;
    for(int i=1;i<=n;i++){
        if((a[i]&t)==t){
            ans++;
        }
    }
    return (ans>=m);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans;
    ans=0;
    for(int j=29;j>=0;j--){
        ans+=(1ll<<j);
        if(!check(ans)){
            ans-=(1ll<<j);
        }
    }
    cout<<ans<<endl;
    return 0;
}
