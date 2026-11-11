#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,m,a[5010],dp[5010][5010],maxn,cnt;
void dfs(int step,int x,int lim){
    if(step>maxn)return ;
    if(x==lim){
        if(step<maxn){
            maxn=step;
            cnt=1;
            return ;
        }
        else{
            cnt++;
        }
    }
    for(int i=n;i>x;i--){
        if(a[i]-a[x]>m)continue;
        dfs(step+1,i,lim);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=1e17;
                cnt=0;
                dfs(0,i,j);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
