#include<bits/stdc++.h>
using namespace std;
#define ull long long
ull a[500010];
int check(int x,int n,int m){
    for(int i=1;i+x-1<=n;++i){
        ull xx=a[i+x-1-1]-a[i-1];
        if((a[i+x-1]-a[i+x-1-1])*(ull)(i+x-1-i)-xx<=m)return 1;
    }return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        t=scanf("%lld",a+i);
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        a[i]+=a[i-1];
        //cout<<a[i]<<' ';
    }ull ma=1;
    /*for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            ull x=a[j-1]-a[i-1];
            if((a[j]-a[j-1])*(j-i)-x<=m&&(j-i+1)>ma){
                ma=j-i+1;
                //cout<<j<<' '<<i<<'\n';
            }
        }
    }cout<<ma;*/
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid,n,m)){
            l=mid;
        }else r=mid-1;
    }cout<<l;
    return 0;
}