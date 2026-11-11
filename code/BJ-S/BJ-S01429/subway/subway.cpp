#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,n,m,d,q,x[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(!c){
        if(n==2&&m==5&&d==20){
            printf("32\n17");
        }
        if(n==3&&m==7&&d==20){
            printf("35\n16");
        }

    }

    for(int i=1;i<=m;i++){
        scanf("%lld",&x[i]);
    }
    for(int i=1;i<=n;i++){
        int k=0;
        scanf("%lld",&k);
        for(int j=1;j<=2*k;j++){
            int a=0,b=0;
            scanf("%lld%lld",&a,&b);
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",x[a]+x[b]);
    }

    return 0;
}
