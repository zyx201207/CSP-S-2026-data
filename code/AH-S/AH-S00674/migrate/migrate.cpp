#include<bits/stdc++.h>

using namespace std;

int c,t;
long long x[2000011];
long long d;
int n;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int w = 1; w <= t; w++){
        scanf("%d%lld",&n,&d);
        for(int j = 1; j <= n; j++)
            scanf("%lld",&x[j]);
        long long ans = 0;
        for(int i = 1; i <= n - 3; i++){
            if(x[i + 1] - x[i] <= d && x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d && x[i + 3] - x[i + 2] <= d && x[i + 3] - x[i] > d)
                ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


