#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[200011][50];
int c[50];
int b[200011];

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i][0]);
    if(m == 1){
        int q = 0;
        for(int i = 1; i <= n; i++){
            q = max(q,a[i][0]);
        }
        printf("%d",q);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int x = a[i][0];
        int q = 0;
        while(x > 0){
            q++;
            a[i][q] = x % 2;
            x /= 2;
        }
        b[i] = q;
    }
    if(m == 2){
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j){
                    memset(c,0,sizeof(c));
                    int q = min(b[i],b[j]);
                    for(int k = 1; k <= min(b[i],b[j]); k++){
                        if(a[i][k] == 1 && a[j][k] == 1){
                            c[k] = 1;
                        }else{
                            c[k] = 0;
                        }
                    }
                    int x = 1;
                    long long z = 0;
                    for(int h = 1; h <= q; h++){
                        z += c[h] * x;
                        x *= 2;
                    }
                    ans = max(ans,z);
                }
            }
        }
        printf("%lld",ans);
        return 0;
    }
    if(m == n){
        int h = 51;
        for(int i = 1; i <= n; i++) {
            h = min(h,b[i]);
        }
        for(int i = 1; i <= h; i++){
            bool t = true;
            for(int j = 1; j <= n; j++) {
                if(a[j][i] == 1){
                    t = false;
                }
            }
            if(!t) c[i] = 1;
            else c[i] = 0;
        }
        int x = 1;
        long long z = 0;
        for(int i = 1; i <= h; i++){
            z += c[h] * x;
            x *= 2;
        }
        printf("%lld",z);
        return 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++){
            if(a[j][0] > a[i][0]) swap(a[j][0],a[i][0]);
        }
    }
    printf("%d",a[n - m + 1][0]);
    return 0;
}
