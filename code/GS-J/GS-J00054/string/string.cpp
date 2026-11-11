#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
            ch = getchar();
        }
    }

    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    string s;
    while(n--){
        long long a;
        string b;
        cin >> a >> b;
        while(a--){
            s += b;
        }
    }


    long long ss = s.size();
    long long cnt = 0;
    for(long long i = 0; i < ss / 2; i++){
        if(s[i] != s[ss - i - 1]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
