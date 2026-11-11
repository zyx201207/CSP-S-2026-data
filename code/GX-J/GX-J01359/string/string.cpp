#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    vector<char> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        char y;
        cin >> y;
        for (long long j = 0; j < x; j++){
            s.push_back(y);
        }
    }
    long long cnt = 0;
    int len = s.size();
    for (long long i = 0; i < len; i++){
        if (s[len-i-1] != s[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
