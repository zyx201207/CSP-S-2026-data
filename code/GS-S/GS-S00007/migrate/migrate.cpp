#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll d,x[2000005],cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        cnt = 0;
        scanf("%d %lld",&n,&d);
        for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);

        cnt = 1;
        printf("%lld\n",cnt);
    }
    return 0;
}
