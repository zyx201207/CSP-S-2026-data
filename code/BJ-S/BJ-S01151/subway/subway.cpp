#include<bits/stdc++.h>
using namespace std;
int n,c,d,q,m;
long long zou[500010],lu[510];
vector<vector<int>> zhan(510);
vector<vector<int>> che(500010);
vector<vector<long long>> dt(510);
long long dp[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>zou[i];
    }
    for(int i=1;i<=n;i++){
        cin>>lu[i];
        for(int j=1;j<=lu[i];j++){
            int x,y;
            cin>>x>>y;
            zhan[i].push_back(x);
            che[x].push_back(i);
            dt[i].push_back(y);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j){
                continue;
            }
            for(int k=0;zhan[i][k];k++){
                for(int h:che[zhan[i][k]]){
                    if(h==j){
                        for(int kk=0;zhan[h][kk];kk++){
                            if(zhan[i][k]==zhan[h][kk]){
                                dp[i][j]=min(dp[i][j],dt[i][k]+dt[h][kk]);
                                dp[j][i]=min(dp[i][j],dt[i][k]+dt[h][kk]);
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i==j){
                continue;
            }
            for(int k:zhan[i]){
                for(int kk:che[k]){
                    if(kk==i||kk==j){
                        continue;
                    }
                    dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
                    dp[j][i]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
 //                   cout<<i<<' '<<j<<' '<<kk<<' '<<dp[i][kk]<<' '<<dp[kk][j]<<endl;
                }
            }
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        long long nmin=0x3f3f3f3f3f3f3f3f;
        for(int i:che[s]){
            for(int j:che[e]){
                    int k=0,kk=0;
                    for(k=0;zhan[i][k];k++){
                        if(zhan[i][k]==s){
                            break;
                        }
                    }
                    for(kk=0;zhan[j][kk];kk++){
                        if(zhan[j][kk]==e){
                            break;
                        }
                    }
                    nmin=min(dp[i][j]+zou[s]+zou[e]+dt[i][k]+dt[j][kk],nmin);
//                    cout<<dp[i][j]<<' '<<k<<' '<<kk<<' '<<i<<' '<<j<<endl;
            }
        }
        cout<<nmin<<endl;
    }
    return 0;
}
