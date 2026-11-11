#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
        long long n,d;
int fun(int a,int b){
    if(a<b)return 0;
    return a-b;
}
pair<int,int>dp[5005][5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(C==11||C==12){
            int cha=a[2]-a[1];
            d=d/cha;
            if(d<=1)cout<<0<<endl;
            long long cnt=0;
            for(int i=1;i<d;i++){
                int f=fun(n,d+i);
                if(f==0)break;
                cnt+=f;
            }
            cout<<cnt<<endl;
        }
        else{
                int cnt=0;
            dp[n][1]={0,0};
            for(int i=n-1;i>=1;i--){
                for(int j=i+1;j<=n;j++){
                    dp[i][j]={d+114514,0};
                    if(a[j]-a[i]>d)break;
                    dp[i][j]={1,1};
                    for(int k=1;k<=n;k++){
                        if(dp[j][k].first==0&&dp[j][k].second==0)continue;
                        if(dp[j][k].first+1<dp[i][k].first)dp[i][k]={dp[j][k].first+1,1};
                        if(dp[j][k].first+1==dp[i][k].first)dp[i][k].second++;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][j].second==2)cnt++;
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
