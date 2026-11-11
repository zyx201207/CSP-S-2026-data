#include<bits/stdc++.h>
using namespace std;
void yu(){
    long long n,m,sum=0;
    cin>>n>>m;
    long long a[n+4];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long dp[n+4];
    dp[0]=0;
    for(int i=4;i<=n;i++){
        dp[i]=0;
        for(int j=i-m;j<i;j++){
            if(a[j]>=a[i]-m){
                dp[i]++;
            }
        }
    }
    for(int i=4;i<=n;i++){
        if(dp[i]==2){
            sum++;
        }
    }
    cout<<sum<<"\n";
    }
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
long long c,b;
cin>>c>>b;
for(int i=1;i<=b;i++){
    yu();
}
return 0;
}
