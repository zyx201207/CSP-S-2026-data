#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005];
int f(int a,int j){
if(j==0) return a;
else return dp[j]&a;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++)
for(int j=min(m,i);j>=1;j--) dp[j] = max(f(a[i],j-1),dp[j]);
cout<<dp[m];
return 0;
}
