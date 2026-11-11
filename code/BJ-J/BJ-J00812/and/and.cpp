#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m,ma=0,ok=1;
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;++i){
        scanf("%lld",&a[i]);
        if(a[i]>ma){ma=a[i];}
        if(a[i]>=4){ok=0;}
    }
    if(m==1){
        printf("%lld",ma);
    }else if(m==n){
        ll sum=a[1];
        for(int i = 2;i <= n;++i){
            sum &= a[i];
        }
        printf("%lld",sum);
    }else if(m==2){
        ma=0;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(i!=j){
                    ll d=a[i]&a[j];
                    ma=max(ma,d);
                }
            }
        }
        printf("%lld",ma);
    }else if(ok){
        ll b[5];
        for(int i = 1;i <= n;++i){
            ++b[a[i]];
        }
        if(b[3]>=m){printf("3");}
        else if(b[3]+b[2]>=m){printf("2");}
        else if(b[3]+b[1]>=m){printf("1");}
        else{printf("0");}
    }else{
        sort(a+1,a+n+1);
        ll sum=a[n];
        for(int i=n-1,j=1;j<m;--i,++j){
            sum &= a[i];
        }
        printf("%lld",sum);
    }
    return 0;
}
