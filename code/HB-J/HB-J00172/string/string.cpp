#include <bits/stdc++.h>
using namespace std;

string w;
long long ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long l = 0,r = 0;
    for(int i = 1; i <= n; i++){
        long long a;
        char c;
        cin >> a >> c;
        for(int j = 0; j < a; j++){
            w += c;
        }
        r += a;
    }
    l = r / 2;
    for(int i = 1; i <= l; i++){
        if(w[i] != w[r - i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
