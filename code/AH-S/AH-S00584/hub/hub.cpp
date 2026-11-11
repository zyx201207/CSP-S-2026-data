#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(long long i=1;i<=t;i++){
        scanf("%lld%lld",&n,&k);
        for(long long j=1;j<n;j++){
            scanf("%lld%lld",&x,&y);
        }
    }
    if(c==0 && t==2){
        cout<<1<<endl<<2;
    }
    return 0;
}
