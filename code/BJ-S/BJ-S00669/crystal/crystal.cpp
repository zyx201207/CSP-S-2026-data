#include<bits/stdc++.h>
using namespace std;

long long dp[500005],n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    double av=0;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            av=av+(a[i]*1.0)/(1.0*n);

    }int y=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++){
        if(m<i*av){
            y=i-1;
            break;
        }
    }
    for(long long i=y-1;dp[i-1]<=m;i++){
            long long minuss=1e18,xb;
        for(int j=1;j<=n-i+1;j++){
            if(minuss>=a[j+i-1]-a[j]){
                xb=j;
                minuss=a[j+i-1]-a[j];
            }
        }double average=0;
        for(long long j=xb;j<=xb+i-1;j++){
            average=average+(a[j]*1.0)/(i*1.0);
        }
        int x1=0,x2=0,aver=average/1,aver2=average/1+1;
        for(long long j=xb;j<=xb+i-1;j++){
            x1+=abs(a[j]-aver);
            x2+=abs(a[j]-aver2);
        }dp[i]=min(x1,x2);
    }for(long long i=1;i<=n;i++){
        if(dp[i]>m){
            cout<<i-1;
            return 0;
        }
    }if(m>=dp[n])cout<<n;
    return 0;
}