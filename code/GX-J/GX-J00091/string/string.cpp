#include<iostream>
struct Data{
    int n;
    char c;
};
Data da[10005];
int8_t bs[27];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>da[i].n>>da[i].c;
    }
    int cnt=0;
    int tys=0;
    for(int i=0;i<n-1;i++){
        if(da[n].c==da[n+1].c){
            bs[(da[n].c-'a')%27]++;
        }
        if(da[i].n!=da[i+1].n){
            cnt+=(da[i].n-da[i+1].n)*2;
            tys++;
        }
        if(da[i].n==da[i+1].n&& bs[da[i].c]>0){
            cnt+=da[i].n;
        }
    }
    if(tys==0){std::cout<<0;return 0;}
    std::cout<<cnt;

    return 0;
}
