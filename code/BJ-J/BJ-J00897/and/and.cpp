#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],vis[N];
int n,m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int k=30;k>=0;k--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            cnt+=(a[i]>>k&1);
        }
        if(cnt<m)continue;
        if(cnt>=m){
            ans+=(1<<k);
            for(int i=1;i<=n;i++){
                if(vis[i])continue;
                if(!(a[i]>>k&1))vis[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}