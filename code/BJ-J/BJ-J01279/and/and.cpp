#include<bits/stdc++.h>
int n,m,a[2000005],max_all;
struct d{
    int nember,th;
}dp[200005];
int main(){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n;i++){
        int now_th,max_;
        for(int j = 1;j <= i,j++){
            if(dp[j].nember >= max_ && dp[j].th <= m - 1){
                if(dp[j].nember > max_ || dp[j].th < now_th){
                    now_th = dp[j].th + 1;
                    max_ = max((max_ & dp[j].nember),max_);
                }
            }
        }
        dp[i].nember = max_,dp[i].th = now_th;
        max_all = max(dp[i].nember,max_all);
    }
    printf("%d",max_all);
    return 0;
}