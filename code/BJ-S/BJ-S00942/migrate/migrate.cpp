//我没招了打了这么久暴力发现思路错了
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int N=2000*1000,FN=10000;//2e6 1e4
ll x[N+10];//1e18 
pil dp[FN+10][FN+10];//<2e6,?>
int main(){
    // freopen("migrate3.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;//25 1e5
    cin>>c>>t;
    while(t--){
        int n,d;//2e6 1e5
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=1;j<=n;j++)dp[i][j]={0,0};
        }
        ll ans=0;//4e12
        // for(int i=1;i<=n;i++){
        //     int l=1;//2e6
        //     ll sum=0;//4e12
        //     for(int j=1;j<=n;j++)dp[j]=0;
        //     for(int j=i;j<=n;j++){
        //         ll&DP=dp[j];//4e12
        //         DP=sum;
        //         if(x[i]+d>=x[j]&&i!=j)DP++;
        //         sum+=DP;
        //         if(DP==2)ans++;
        //     }
        //     for(int j=1;j<=n;j++)cout<<dp[j]<<' ';
        //     cout<<'\n';
        // }
        for(int i=1;i<=n;i++)dp[i][i]={0,1};
        // for(int i=1;i<n;i++)
        //     if(x[i]+d>=x[i+1])
        //         dp[i][i+1]={1,1};
        for(int len=2;len<=n;len++)
            for(int l=1;(l+len-1)<=n;l++){
                int r=l+len-1;//2e6
                pil&DP=dp[l][r];//<2e6,?>
                if(x[l]+d>=x[r])DP={1,1};
                else DP={0x7f7f7f7f7f7f7f7f,0};
                ll&DP2=DP.second;//?
                for(int i=l+1;i<r;i++){
                    pil DPl=dp[l][i],DPr=dp[i][r];//<2e6,?> <2e6,?>
                    int&DP1=DP.first,dis=DPl.first+DPr.first;//2e6 2e6
                    // cout<<'\t'<<l<<' '<<r<<' '<<i<<' '<<d<<' '<<DPl.second*DPr.second<<'?'<<DP1<<' '<<DP2<<'\n';
                    if(dis>DP1)continue;
                    ll cnt=DPl.second*DPr.second;//? ?
                    if(dis==DP1)DP2+=cnt;
                    else DP={dis,cnt};//<
                }
                if(DP2==2)ans++;
            }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         pil DP=dp[i][j];//<2e6,?>
        //         cout<<DP.first<<' '<<DP.second<<"  ";
        //     }
        //     cout<<'\n';
        // }
        cout<<ans<<'\n';
    }
    return 0;
}