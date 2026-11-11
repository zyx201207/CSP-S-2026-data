#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ma,f[200010],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    for(int i=__lg(ma); i>=0; i--){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(f[j]==0 && (a[j]&(1ll<<i))!=0){
                cnt++;
            }
        }
        if(cnt<m){
            continue;
        }
        ans+=(1ll<<i);
        for(int j=1; j<=n; j++){
            if(f[j]==0 && (a[j]&(1ll<<i))==0){
                f[j]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
