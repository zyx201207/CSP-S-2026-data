#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int dp[maxn]={};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int lis[n+1];
    for(int i=1;i<=n;i++){
        cin >> lis[i];
    }
    lis[0]=0;
    
    sort(lis,lis+n+1);
    for(int i=0;i<=n;i++){
        for(int j=m;j>0;j--){
            if(j==1){
                dp[j]=lis[i];
            }else{
                dp[j]=max(dp[j],(dp[j-1]&lis[i]));
            }
        }
        /*for(int j=0;j<=m;j++){
            cout << dp[j] << ' ';
        }cout << endl;*/
    }
    cout << dp[m];
    
    return 0;    
}