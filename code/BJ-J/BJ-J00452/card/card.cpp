#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int n,m;
int lst[M];
int dp[N];
int ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[n+1]=0;
    for(int i=1;i<=n;i++) lst[a[i]]=i;
    for(int i=1;i<=n;i++){
        dp[i]++;
        dp[lst[a[i]]+1]+=dp[i];
        ans[a[i]]+=dp[i];
    }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}