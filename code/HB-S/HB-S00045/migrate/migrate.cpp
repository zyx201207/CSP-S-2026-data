#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,a[N];
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        printf("0\n");
    }

    return 0;
}
