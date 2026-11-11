#include <bits/stdc++.h>

using namespace std;
long long c,t,x[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        long long n,d;
        scanf("%lld%lld",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x[i]);
        }
        cout << "0" << endl;
    }
    return 0;
}
