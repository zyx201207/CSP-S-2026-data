#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1;
void solve1(){
    for(long long i=n;i>=1;i--){
        long long mm=m,sum=1;
        for(long long j=i-1;j>=1;j--){
            if(mm<(a[i]-a[j])){
                break;
            }
            mm-=(a[i]-a[j]);
            sum++;
        }
        ans=max(sum,ans);
    }
}
void solve2(){
    long long mm=m,sum=1;
    for(long long j=n-1;j>=1;j--){
        if(mm<(a[n]-a[j])){
            break;
        }
        mm-=(a[n]-a[j]);
        sum++;
    }
    ans=sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    long long maxa=0;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxa=max(a[i],maxa);
    }
    sort(a+1,a+1+n);
    if(maxa>100&&n>5000){
        solve2();
    }else{
        solve1();
    }
    cout<<ans;
    return 0;
}
