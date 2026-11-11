#include<bits/stdc++.h>
using namespace std;

// #define LOCAL
int n,res;
long long m,a[500010],d[500010];
int main(){
    // #ifndef LOCAL
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // #endif
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    // cha fen
    for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];

    // for 13 - 18
    long long dx=0x8000000000000000;
    bool equ=true;
    for(int i=2;i<=n;i++){
        if(dx!=0x8000000000000000&&dx!=d[i]){
            equ=false;
            break;
        }
        dx=d[i];
    }

    if(equ&&dx==1){
        // for 13 - 15
        long long t=0;
        for(long long i=1;i*(i+1)/2<=m;i++){t=i;}
        res=t+1;
    }else if(equ&&dx!=1){
        // for 16 - 18
        // abs
        dx=(dx<0)?(0-dx):(dx);
        long long t=0;
        for(long long i=1;dx*i*(i+1)/2<=m;i++){t=i;}
        res=t+1;
    }
    if(!equ){
        // left n right
        int resl=1;
        int resr=1;

        // choose the most
        // right first
        long long fled=0;
        for(int r=n;fled<=m;r--){
            fled+=d[r];
            resr++;
        }
        if(fled>m)resr--;

        // then left
        fled=0;
        for(int l=1;fled<=m;l++){
            fled+=l*d[l];
            resl++;
        }
        if(fled>m)resl--;

        res=max(resl,resr);
    }

    // found answer => minified s^2
    printf("%d",res);
    return 0;
}