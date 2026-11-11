#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
int dp[1000][1000];
int f(int i,int j){
    if(dp[i][j]!=0)return dp[i][j];
    if(i==j){
        int an=a[0];
        for(int i=1;i<j;i++)an=an&a[i];
        return an;
    }
    dp[i][j]=max(f(i-1,j),f(i-1,j-1)&a[i]);
    return dp[i][j];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<f(n-1,m);
    return 0;
}
