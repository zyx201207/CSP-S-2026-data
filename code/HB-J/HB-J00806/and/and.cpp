#include<bits/stdc++.h>
using namespace std;

long long a[100010];long long n,m;

long long and_(long long a,long long b){
    long long c=0;
    while(a!=0 && b!=0){
        if(a%2==1 && b%2==1){
            c*=2,c++;
        }
        a/=2,b/=2,c*=2;
    }
    return c;
}

void s1(){
    long long ans =-1;
    for(long long i=1;i<=n;i++){
        ans = max(a[i],ans);
    }
    cout << ans;
    return ;
}

void s2(){
    long long ans = and_(a[1],a[2]);
    for(long long i=3;i<=n;i++){
        ans = and_(a[i],ans);
    }
    cout << ans;
    return ;
}

void s3(){
    long long ans = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                ans = max(and_(a[i],a[j]),ans);
            }
        }
    }
    cout << ans;
    return ;

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m == 1){
        s1();
        return 0;
    }
    if(m==n){
        s2();
        return 0;
    }
    if(m==2){
        s3();
        return 0;
    }
    return 0;
}
