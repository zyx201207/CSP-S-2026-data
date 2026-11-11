#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,sum=1;
cin>>n>>m;
long long a[n+4],dp[n+4];
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
dp[0]=0;
for(long long i=2;i<=n;i++){
    long long s=m,j=i-1,ai[n+4];
    for(long long k=1;k<=i;k++){
        ai[k]=a[k];
    }
    while(s!=0){
        if(ai[j]==ai[i]){
            j--;
        }
        if(j==0){
            break;
        }
        s--;
        ai[j]++;
        if(ai[j]==ai[i]){
            j--;
        }
    }
    sum=max(sum,i-j);
}
cout<<sum;
return 0;
}