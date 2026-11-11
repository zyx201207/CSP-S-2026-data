#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long v[n];
    unsigned long long dp[m+1]={0};
    dp[0]=0b11111111111111111111111111111;
    //cout<<dp[0]<<' '<<((15)&(1<<31))<<endl;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=m;j>0;j--){
            dp[j]=dp[j-1]&v[i]>dp[j]?dp[j-1]&v[i]:dp[j];
            //cout<<dp[j]<<' ';
        }
        //cout<<dp[0]<<endl;
    }
    cout<<dp[m];
    return 0;
}