#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=2e5+1;
int n,m,dp[N],a[N],num1,num2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
    }
    for(int i=2;i<=m;i++){
        num1=dp[i-1];
        for(int j=i;j<=n-m+i;j++){
            num2=dp[j];
            if(j==i){
                dp[j]=a[j]&num1;
            }else{
                dp[j]=max(dp[j-1],a[j]&num1);
            }
            num1=num2;
        }
    }
    printf("%d",dp[n]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}