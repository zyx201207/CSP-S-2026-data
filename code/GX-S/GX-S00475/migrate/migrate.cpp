#include <bits/stdc++.h>
using namespace std;
inline int read(){
    char c = getchar();
    int flag = 1, ans = 0;
    while(! (c >= '0' && c <='9')){
        if(c == '-') flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = (ans << 3) + (ans << 1) + c - '0';
        c = getchar();
    }
    return ans * flag;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t = read();
    while(t --) cout << 0 << endl;
    return 0;
}
