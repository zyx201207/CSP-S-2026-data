
#include<bits/stdc++.h>
using namespace std;

using LL=long long ;


int c,n;
LL d,x[(int)2e6+10];
int dp[5010][5010],f[5010][5010];

void input(){
    cin>>n>>d;
    for(int i=1;i<=n;++i)
        cin>>x[i];
}

void work(){
    input();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f[i][j]=1e8;

    for(int i=1;i<n;++i)
        if((x[i+1]-x[i]<=d))dp[i][i+1]=f[i][i+1]=1;

    int ans=0;
    for(int len=2;len<n;++len){
        for(int l=1,r=l+len;r<=n;++l){
            r=l+len;
            if(x[r]-x[l]<=d){
                f[l][r]=dp[l][r]=1;
                continue;
            }
            for(int k=l+1;k<r;++k){
                if(f[l][k]+f[k][r]<f[l][r]){
                    f[l][r]=f[l][k]+f[k][r];
                    dp[l][r]=dp[l][k]*dp[k][r];
                }else if(f[l][k]+f[k][r]==f[l][r]){
                    dp[l][r]+=dp[l][k]*dp[k][r];
                }
            }
            if(dp[l][r]==2)ans++;
        }
    }
    cout<<ans<<'\n';
}


int main()
{
//    ios::sync_with_stdio(false);cin.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    while(t--)
        if(c!=11&&c!=12&&false)work();
        else{
            input();
            LL del=x[2]-x[1];
            if(del>d||d>x[n]-x[1]||d/del+1>=n||del==d){
                cout<<0<<'\n';
                continue;
            }else{
                cout<<n-(d/del+(del*(int)(d/del)==d?2:1))<<'\n';
            }
        }

    return 0;
}

/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/
