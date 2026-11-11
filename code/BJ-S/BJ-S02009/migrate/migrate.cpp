#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,x[N],cnt[N],num[N],vis[N],ans;
void dfs(int now){
    for(int i=now+1;i<=n;i++){
        if(x[i]-x[now]<=d){
            if(num[i]==num[now]+1){
                cnt[i]++;
            }else if(num[i]>num[now]+1){
                num[i]=num[now]+1;
                cnt[i]=1;
                dfs(i);
            }
        }
    }
    for(int i=now-1;i>=1;i--){
        if(x[now]-x[i]<=d){
            if(num[i]==num[now]+1){
                cnt[i]++;
            }else if(num[i]>num[now]+1){
                num[i]=num[now]+1;
                cnt[i]=1;
                dfs(i);
            }
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        // memset(vis,0,sizeof(vis));
        memset(num,0x3f,sizeof(num));
        memset(cnt,0x3f,sizeof(cnt));
        num[i]=0;
        cnt[i]=0;
        dfs(i);
        // cout<<"i:"<<i<<"\n";
        for(int j=1;j<=n;j++){
            // cout<<"j:"<<j<<" "<<num[j]<<" "<<cnt[j]<<"\n";
            if(cnt[j]==2){
                ans++;
            }
        }
        // cout<<"ans:"<<ans<<"\n";
    }
    cout<<ans/2<<"\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;cin>>C>>T;
    while(T--){
        ans=0;
        solve();
    }
    return 0;
    //tt520
}