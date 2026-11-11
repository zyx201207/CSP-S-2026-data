#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10,N2=5e3;
const long long INF=1e9;
int c,T,n,dp[N2][N2],f[N2][N2],ans;
long long x[N],d;
void solve1(){
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            f[i][i]=1;
            for(int j=i+1;j<=n;j++){
                int k=j-1,dpij=INF,fij=0;
                while(x[j]-x[k]<=d&&k>=i){
                    if(dp[i][k]+1<dpij){
                        dpij=dp[i][k]+1;
                        fij=f[i][k];
                    }else if(dp[i][k]+1==dpij){
                        fij+=f[i][k];
                    }
                    k--;
                }
                if(dpij==INF)break;
                dp[i][j]=dpij;
                f[i][j]=fij;
                if(f[i][j]==2) ans++;
                // cout<<f[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<ans<<'\n';
    }
}
void solveA(){
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int t=d/(x[2]-x[1]);
        if(t>1){
            cout<<max(0,n-t*2+1)<<'\n';
        }
        else{
            cout<<"0\n";
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c<=10){
        solve1();
    }else{
        solveA();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/