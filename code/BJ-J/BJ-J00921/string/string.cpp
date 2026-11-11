#include<bits/stdc++.h>
using namespace std;
long long n, a, cnt = 0;
char c;
string s1, s2;
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int tmp = n;
    while(tmp--){
        cin >> a >> c;
        for(int i = 1; i <= a; i++){
            s1 += c;
        }
    }
    long long len = s1.size();
    s1 = ' ' + s1;
    for(int i = 1; i <= len / 2 + 1; i++) s2[len - i + 1] = s1[i];
    for(int i = len; i >= len / 2 + 1; i--) if(s1[i] != s2[i]) cnt++;
    cout << cnt;
    return 0;
}
