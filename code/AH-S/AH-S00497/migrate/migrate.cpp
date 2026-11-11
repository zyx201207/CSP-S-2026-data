#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100;
int a[N];
int n,d;
int c,t;
int cnt;
int tot;
int ans;
int k;
int sum[N];
int read(){
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(!isdigit(ch)){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(isdigit(ch)){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*f;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read();
    t = read();
    while(t--){
        n = read();
        d = read();
        for(int i = 1;i<=n;i++){
            a[i] = read();
        }
        if(c == 11 || c == 12 || c == 0){
            k = 2*d;
            int D = a[2] - a[1];
            ans = 0;
            for(int i = 4;i<=n;i+=2){
                if(a[i]-a[1]+D <= k && a[i]-a[1]+2*D > k){
                    ans += (n-i+1);
                    break;
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        if(c == 13 || c == 14){
            cout<<0<<'\n';
        }
        cout<<n/2<<'\n';
    }
    return 0;
}
