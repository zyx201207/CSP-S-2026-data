#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int num[2000005];
signed long long num1[2000005];
int dp[2000005]; // 最短距离
int dp1[2000005];
int lft[2000005];
int c,n,k,q,ans;
void init(){
    for(int i=1;i<=n;i++){
        num[i]=0;
        dp[i]=0;
        dp1[i]=0;
        lft[i]=0;
        num1[i]=0;
    }
    n=0,k=0;
    ans=0;
    return ;
}
void solve(){
    //cout<<"=============================\n";
    cin>>n>>k;
    //cout<<n<<' '<<k<<'\n';
    for(int i=1;i<=n;i++){
        cin>>num1[i];
    }
    for(int i=1;i<=n;i++){
        if(num1[1]<0){
            signed long long tmp=(num1[i]-num1[1]+1);
            num[i]=tmp;
        }
        else{
            num[i]=(unsigned long long)(num1[i]);
        }
    }
    //cout<<'\n';
    int l=1;
    lft[1]=1ull;
    for(int r=2;r<=n;r++){
        //cout<<"!"<<r<<"!"<<'\n';
        while(l<r && num[r]-num[l]>k){
            //cout<<l<<' '<<r<<' '<<(num[r]-num[l])<<' '<<k<<'\n';
            l++;
        }
        lft[r]=l;
        //cout<<lft[r]<<'\n';
    }
    for(int i=2;i<=n;i++){
        int mn=2e18+10;
        for(int j=lft[i];j<i;j++){
            dp1[i]+=dp1[j];
            mn=min(mn,dp[j]+1ull);
        }
        dp[i]=mn;
        int cnt=0;
        for(int j=lft[i];j<i;j++){
            if(dp[j]+1ull==mn)
                cnt++;
        }
        if(cnt==2ull)
            dp1[i]++;
        ans+=dp1[i];
    }
    //for(int i=2;i<=n;i++){
        //cout<<dp[i]<<' ';
    ///}
    cout<<ans<<'\n';
    return ;
}
signed main(){
//int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>q;

    while(q--){
        init();
        solve();
    }
    return 0;
}
