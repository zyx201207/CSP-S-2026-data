/*
===10:17===
wtf is this
isnt this just mo'ni?

nonono this is another dp

===10:59===
logic is correct but tle seriously
O(n^2*m^2)
what should i do...

===11:06===
give up, 100+100+0+12=212pts?
*/
#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[3005];
bool dp[200005][3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        for(int j=i;j<=n;j++){
            if(dp[j-1][a[j]]==0){
                for(int p=1;p<=m;p++){dp[j][p]=dp[j-1][p];}
            }else{
                for(int k=j-1;k>=i-1;k--){
                    if(dp[k][a[j]]==0){
                        for(int p=1;p<=m;p++){dp[j][p]=dp[k][p];}
                        break;
                    }
                }
            }
            dp[j][a[j]]=1;
// for(int p=1;p<=m;p++){
// cout<<dp[j][p]<<' ';
// }
// cout<<'\n';
        }
        for(int p=1;p<=m;p++){
            if(dp[n][p]){cnt[p]++;}
// cout<<dp[n][p]<<' ';
        }
// cout<<"\n\n";
    }
    for(int p=1;p<=m;p++){cout<<cnt[p]<<' ';}
    return 0;
}
/*
1 2 1 3

    1   2   3   4
1 100
2 110 010
3 100 110 100
4 101 111 101 001 = 314
*/