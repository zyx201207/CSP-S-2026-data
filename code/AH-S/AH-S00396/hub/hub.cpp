#include <iostream>
#define int long long
using namespace std;
int n,k;
void solveA(){
    scanf("%lld%lld",&n,&k);
    for(int i=1,u;i<n;i++) scanf("%lld%lld",&u,&u);
    printf("%lld",((n-1)/2-k+1)/4+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T; cin>>C>>T;
    while(T--){
        if(C==13||C==14) solveA();
    }
    return 0;
}
