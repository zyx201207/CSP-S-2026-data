#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int x){
    if(x==1){
        return true;
    }
    int cnt=0;
    for(int i=2;i<=x;i++){
        cnt+=(a[i]-a[i-1])*(i-1);
    }
    for(int i=x+1;i<=n;i++){
        if(cnt<=m){
            return true;
        }
        cnt+=(a[i]-a[i-1])*x;
        cnt-=a[i]-a[i-x];
    }
    return cnt<=m;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
