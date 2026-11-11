#include<bits/stdc++.h>

using namespace std;

long long n;
long long m;
long long a[500011];
long long b[500011];
long long cnt = 0;
long long c[500011];
long long ans = 0;
bool t = true;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(long long i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
        cnt = max(cnt,a[i]);
    }
    for(long long i = 3; i <= n; i++) {
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
            t = false;
    }
    if(t){
        int o = a[2] - a[1];
        int x = o;
        ans = 1;
        while(m >= x){
            m = m - x;
            ans++;
            if(m >= x){
                m = m - x;
                ans++;
                x = x + o;
            }
        }
        ans = min(ans,n);
        printf("%lld",ans);
        return 0;
    }
    for(long long i = 1; i <= cnt; i++){
        for(int j = 1; j <= n; j++){
            if(a[j] >= i) c[j] = a[j] - i;
            else c[j] = i - a[j];
        }
        sort(c + 1,c + n + 1);
        long long q = m,w = 1;
        long long z = 0;
        while(q >= c[w]){
            q = q - c[w];
            w++;
            z++;
        }
        ans = max(ans,z);
    }
    printf("%lld",ans);
    return 0;
}
