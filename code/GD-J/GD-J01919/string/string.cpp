#include <iostream>
#include <string>
using namespace std;
long long hw(string t){
    long long l = 0, r = t.size() - 1;
    long long cnt = 0;
    while (l < r){
        if (t[l] != t[r]){
            cnt++;
        }
        l++;
        r++;
    }
    return cnt;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++){
        long long a;
        string c;
        cin >> a;
        cin >> c;
        for (long long j = 0; j < a; j++){
            s += c;
        }
    }
    cout << hw(s);
    return 0;
}
