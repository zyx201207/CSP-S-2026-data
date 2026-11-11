#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],s[500005],m,ans;
bool check(int l,int r){
    return (r-l+1)*a[r]-s[r]+s[l-1]<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l+1<r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                r=mid;
            }else{
                l=mid;
            }
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<'\n';
    return 0;
}
