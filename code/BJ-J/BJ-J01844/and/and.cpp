#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=2e5+10;
int n,m,s;
ULL mx=0;
ULL a[N];
ULL dp[N];
ULL ep;
ULL lowbit(ULL x,ULL y){
    return x&y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        dp[0]=a[1];
        dp[i]=lowbit(a[i],dp[i-1]);
    }
    if(m==1){
        printf("%d",mx);
        return 0;
    }
    else if(m==n){
        printf("%d",dp[n]);
        return 0;
    }
    ULL y=a[1];
    int e=0;
    for(int i=1;i<=n;i++){
            ep=a[i];
        for(int j=i;j<=n;j++){
            int h=ep;
            ep=max(ep,lowbit(ep,a[i]));
            if(ep!=h){
                e++;
            }
        }
        y=max(ep,y);
    }
    cout<<ep;
    return 0;
}
