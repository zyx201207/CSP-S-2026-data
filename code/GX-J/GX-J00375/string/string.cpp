#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    int top = 0;
    for(int i = 0;i < n;i++){
        int f;
        char c;
        cin >> f >> c;
        for(int j = 0;j < f;j++){
            s[top] = c;
            top++;
        }
        s[top] = '\0';
    }
    cout << 0 << '\n';

    return 0;
}
