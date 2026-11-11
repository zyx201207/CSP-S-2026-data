#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[1005][1005];
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int maxx2=-1e9;
   int maxx=-1e9;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   	maxx=max(maxx,a[i]);
   }
   cout<<maxx;
   
   
   	return 0;
} 
