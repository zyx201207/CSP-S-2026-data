#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;
int dp[N];
int pre[N];
int a[N];
int nu;
int n,m;
int ans;

void cs(){
    for(int i=2;i<=n;i++){
        pre[i]=a[i]-a[i-1]+pre[i-1];
    }
}


void tj(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if((pre[i]-pre[i-1]<=m)&&dp[i]==m) {
                cnt++;
        }
    }
    ans=max(ans,cnt);
}
void solve(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cs();
    for(int j=1;j<=n;j++)
    {
        dp[j-1]=0;
        for(int i=j;i<=n;i++){
            dp[i]=dp[pre[i]-pre[j]/m]+(pre[i]-pre[j]%m);
        }
        tj();
    }
}


int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin>>c;
    cin>>nu;
    for(int i=1;i<=nu;i++){
        cin>>n>>m;
        solve();
        cout<<ans<<endl;
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        memset(a,0,sizeof(a));
    }
return 0;
}
