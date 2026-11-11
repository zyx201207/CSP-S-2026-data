#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int pre[500010];
int n;
int m;
bool check(int u){
    for(int i=u;i<=n;i++){
        int cnt = pre[i]-pre[i-u];
        if(a[i]*u-cnt<=m){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    int l=1,r=n;
    int ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
//14:47 ok 4 substack
//just joking just now