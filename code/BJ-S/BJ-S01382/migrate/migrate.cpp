#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
inline int read(){
    int x=0, f=1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = x*10 + (ch^48);
        ch = getchar();
    }
    return x*f;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = read(), t = read();
        while (t--){
            int n = read(), d = read();
            for (int i = 1; i <= n; i++){
                a[i] = read();
            }
            int dd = a[2]-a[1], sd = d/dd;
            if (sd < 2){
                cout << 0 << "\n";
            }
            else if (sd == 2){
                cout << n-3 << "\n";
            }
            else if (n-1 < 2*sd-1){
                cout << 0 << "\n";
            }
            else if (n-1 >= 2*sd-1){
                cout << n- 2*sd+1 << "\n";
            }else{
                cout << 0;
            }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
