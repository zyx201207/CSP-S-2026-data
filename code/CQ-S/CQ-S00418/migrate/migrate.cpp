#include<bits/stdc++.h>
#define ll long long
#define pii pair<int ,int >
#define pll pair<long long, long long >

using namespace std;
const ll N=2e6+5,M=505,W=1e9,mod=998244353,INF=1e18;
ll n,m,d,q,arr[N],ans,dp[N][3][3][3];
int nxt[N];
void sol(){
    ans=0;

    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        cin>>arr[i];
        for(int a=0;a<=2;++a){
            for(int b=0;b<=2;++b){
                for(int c=0;c<=2;++c){
                    dp[i][a][b][c]=0;
                }
            }
        }
    }
    arr[n+1]=n;
    for(int i=1;i<=n;++i){
        int l=i,r=n,res=n;
        while(l<=r){
            int mid=l+r>>1;
            if(arr[mid]-arr[i]<=m){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        nxt[i]=res;
    }
    nxt[0]=1;
    for(int i=1;i<=n;++i){
        dp[i][1][0][0]++;
        //j=2
        int r=nxt[i],l=max(nxt[i-1]+1,i+1);
        if(r!=i&&l<=r){
            for(int a=0;a<=2;++a){
                ans+=(r-l+1)*(dp[i][2][1][a]+dp[i][2][2][a]);
            }
            for(int a=0;a<=2;++a){
                dp[r][2][2][min(2,a+r-i)]+=dp[i][2][1][a]+dp[i][2][2][a];
            }
        }
        //j=1
        //先转移吧
        for(int a=0;a<=2;++a){
            dp[r][1][1][min(2,a+r-i)]+=dp[i][1][0][a];
        }
        if(r==i){
            continue;
        }
        l=nxt[i-1];
        if(l==r){
            for(int a=0;a<=2;++a){
                if(a==2&&i==1)continue;
                if(a!=2||nxt[i-2]<r){
                    dp[r][2][2][min(2,a+1)]+=dp[i][1][1][a];
                }
            }
        }
        else if(l==r-1){
            for(int a=0;a<=2;++a){
                dp[r][1][2][min(2,a+2)]+=dp[i][1][1][a]+dp[i][1][2][a];
            }
        }
        else{
            for(int a=0;a<=2;++a){
                dp[r][1][1][min(2,a+2)]+=dp[i][1][1][a]+dp[i][1][2][a];
            }
        }

        //更新ans
        //i,1,1
        //cerr<<i<<' '<<ans<<'\n';
        for(int a=0;a<=2;++a){
            if(a==2&&i==1)continue;
            int r=nxt[i-1];
            int l=i+1;
            if(a==2){
                l=max(l,nxt[i-2]+1);
            }
            if(l<=r){
                ans+=(r-l+1)*dp[i][1][1][a];
            }
            //cerr<<"aa "<<a<<" "<<ans<<'\n';
        }
        //cerr<<i<<' '<<ans<<'\n';
    }
    cout<<ans<<'\n';


}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t=1;
    int c=0;
    //cin>>t;
    cin>>c>>t;
    while(t--){
        sol();
    } 
    //cerr<<clock();
    return 0;
}
/*
author:_aa_
前三题是黄青蓝吧

*/
