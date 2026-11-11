#include<iostream>
#include<vector>
using namespace std;


const int M=5e5+10;
int dp[550][550];
int c,n,m,d,q;
int substa[550];
int ostatm[M];
//int staonsub[M][22];
int istatm[300010][510];
int ki;
int p;
int p2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> staonsub[M];
    //pair<int> instatm[M];
    freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    //
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>ostatm[i];
    }
    for(int i=1;i<=n;i++){
        cin>>ki;
        substa[i]=ki;
        for(int j=1;j<=ki;j++){
            cin>>p;
            staonsub[p].push_back(i);
            cin>>p2;
            instatm[p][i]=p2;
        }
    }
    for(int i=0;i<=510;i++){
        for(int j=0;j<=510;j++){
            dp[i][j]=1000000000;
            dp[i][i]=0;
        }
    }
    for(int i=1;i<=M;i++){
        if(staonsub[i].size()>1){
            for(int i=1;i<staonsub[i].size();i++){
                for(int j=i+1;j<=staonsub[i].size();j++){
                    dp[i][j]=dp[j][i]=min(dp[i][j],)
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        
    }

    return 0;
}


//完啦
//没时间啦
//哈哈哈哈
//T-T
//···   -···
//可惜了
//第一次参加S组
//明年再战

