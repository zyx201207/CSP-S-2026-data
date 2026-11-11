#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+10;
int c,t;
int n;
ll d;
ll x[MAXN];
int pre[MAXN],nxt[MAXN],cnt[MAXN];
ll dp[MAXN],dp2[MAXN],dp3[MAXN],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        //cout<<d<<' '<<x[2]-x[1]<<'\n';
        //if(d==x[2]-x[1]) cout<<"!!!\n";
        //cout<<d<<' '<<x[2]-x[1]<<'\n';
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
            nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            dp[i]=dp2[i]=dp3[i]=0;
            cnt[pre[i]]++;
        }
        //cout<<"now;"<<now<<'\n';
        for(int i=n-1;i>=1;i--){
            if(nxt[i]==i) continue;
            if(pre[nxt[nxt[i]]]==nxt[i]){
                dp[i]=dp[nxt[i]];
                dp3[i]=dp3[nxt[i]];
                if(pre[nxt[nxt[i]]-1]==nxt[i]) dp3[i]+=dp2[nxt[i]];
                //cout<<i<<' '<<dp[i]<<' '<<dp2[i]<<'\n';
            }
            else if(pre[nxt[nxt[i]]]+1==nxt[i]){
                dp2[i]+=dp[nxt[i]];
            }
            dp[i]+=cnt[nxt[i]];
            if(nxt[i]!=i+1){
                dp2[i]+=cnt[nxt[i]-1];
            }
            ans+=dp2[i]+dp3[i];
        }/*
        for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<dp2[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=n;i++) cout<<dp3[i]<<' ';
        cout<<'\n';*/
        cout<<ans<<'\n';
    }
    return 0;
}
/*
5 3
-3 0 2 3 4
*/
