#include<bits/stdc++.h>
// #define int lng long
using namespace std;
const int MAXN=2e5+5;
long long n,m,ans=0xFFFFFFFFFFFFFFFF,a[MAXN];
bool flag[MAXN],vis[MAXN];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=30;i>=0;--i){
        // cout<<i<<"}\n";
        memset(flag,1,sizeof flag);
        long long cnt=0;
        for(int j=1;j<=n;++j){
            if(vis[j]) continue;
            if(a[j]&(1<<i)){
                // cout<<j<<" ";
                flag[j]=0;
                cnt++;
            }
        }
        // cout<<"\n";
        if(cnt>=m){
            // cout<<i<<"\n";
            for(int j=1;j<=n;++j){
                vis[j]|=flag[j];
            }
        }
    }
    for(int i=1;i<=n;++i){
        // cout<<vis[i]<<"\n";
        if(!vis[i]){
            ans&=a[i];
        }
    }
    cout<<ans<<"\n";
}