#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001],s[200005];
int dp[20001][20001];
int mx1(int i,int j,int n1){
int sum=-1000;
for(int x=1;x<i;x++){
    sum=max(sum,n1&dp[x][j-1]);
}
return sum;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    dp[i][1]==a[i];
}
if(m==1){
    sort(a+1,a+n+1);
    cout<<a[n];
    return 0;
}
if(m==n){
    int k=a[1];
    for(int i=2;i<=n;i++){
        k&=a[i];
    }
    cout<<k;
    return 0;
}

s[1]=a[1];
for(int i=2;i<=n;i++){
    s[i]=s[i-1]&a[i];
}

for(int j=2;j<=m;j++){
        dp[j][j]=s[j];
    for(int i=j+1;i<=n;i++){
        dp[i][j]=max(dp[i-1][j],mx1(i,j,dp[i][1]));
    }
}
cout<<dp[n][m];
return 0;
}