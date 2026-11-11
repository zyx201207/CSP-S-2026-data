#include<iostream>
int c,t;
long long n,k;
long long u[1000005],v[1000005];
int hub(long long i,long long j){
    int n;
    if(i-j>=j)n=(i-j-(i-j%j))/j;
    else n=1;
    return n;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    std::cin.tie(0);

    std::cin>>c>>t;
    for(int w=1;w<=t;w++){
        std::cin>>n>>k;
        for(int i=1;i<=n-1;i++)std::cin>>u[i]>>v[i];
        std::cout<<hub(n,k)<<std::endl;
    }
}
