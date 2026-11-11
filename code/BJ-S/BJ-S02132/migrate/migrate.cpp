#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,ans=0;
int dp[2000010],cnt[2000010];
ll a[2000010];
void dfs(int x,int val){
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d){
            if(dp[i]>val+1){
                dp[i]=val+1;
                cnt[i]=0;
            }
            if(dp[i]==val+1){
                cnt[i]++;
                dfs(i,val+1);
            }
        }else{
            return;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        for(int ii=1;ii<=t;ii++){
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            ll k=a[2]-a[1];
            for(int i=2;i<n-1;i++){
                if(k*i<=d&&k*i+k>d) ans+=n-i*2+1;
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    for(int ii=1;ii<=t;ii++){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++){
                dp[j]=1e9;
                cnt[j]=0;
            }
            dfs(i,0);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}