#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m;
const long long N=pow(2,30);
int check(int k){
    int ans=0;
    for(int i=1;i<=n;i++){
        if((a[i]&k)==k) ans++;
    }
    return ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(1){
        int maxs=0,k=1;
        for(int i=1;i<=30;i++){
            if(check(ans+k)>=m){
                maxs=max(maxs,k);
            }
            k*=2;
        }
        if(maxs!=0) ans+=maxs;
        else break;
    }
    cout<<ans;
    return 0;
}
