#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200009],vis[200009];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int ans=0;
    for(int i=31;i>=0;--i){
        int cnt=0;
        for(int j=1;j<=n;++j){
            if(vis[j]==1){
                continue;
            }
            if(bool(a[j]&(1<<i))==1){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;++j){
                if(vis[j]==1){
                    continue;
                }
                if(bool(a[j]&(1<<i))==0){
                    vis[j]=1;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}