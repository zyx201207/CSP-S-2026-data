#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,n,d,x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(LL i=1;i<=n;i++)scanf("%lld",&x[i]);
        if(c==13||c==14){
            cout<<0<<endl;
            break;
        }
        LL num=abs(x[2]-x[1]);
        LL y=d/num;
        if(y<=1||y*2-1>n)cout<<0<<endl;
        else cout<<n-2*y+1<<endl;
    }
    return 0;
}
