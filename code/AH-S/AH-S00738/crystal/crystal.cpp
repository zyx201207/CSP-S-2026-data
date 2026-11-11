#include"bits/stdc++.h"

typedef int i32;
typedef long long i64;

const int N=5e5+10;
int n;
long long m,a[N],s[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin>>n>>m;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::sort(a,a+n);
    i64 cost=0;
    s[0]=0;
    for(i32 i=1;i<n;i++){
       i64 delta=a[i]-a[i-1];
       cost+=(delta*i);
       s[i]=cost;
    }
    i32 r=0,len=1;
    bool is_over=false;
    cost=0;
    //cost=s[r]-s[l]-(a[r]-a[l])*l;
    for(i32 l=0;l<n;l++){
        while(true){
            r=l+len-1;
            ++r;
            if(r>=n){
                is_over=true;
                break;
            }
            cost=s[r]-s[l]-(a[r]-a[l])*l;
            if(cost>m){
                break;
            }
            ++len;
        }
        if(is_over){
            break;
        }
    }
    std::cout<<len;
    return 0;
}
