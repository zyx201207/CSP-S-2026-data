#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
char s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int z = 0;
    for (int i = 1;i <= n;i++){
        int x;
        char c;
        cin >> x >> c;
        for (int j = 1;j <= x;j++){
            s[z] = c;
            z++;

        }
    }
    z -= 1;
    long long o = 0;
    for (int i = 0;i * 2 <= z;i++){
        if (s[i] != s[z - i]){
            o++;
        }
    }
    cout << o;
    return 0;
}
