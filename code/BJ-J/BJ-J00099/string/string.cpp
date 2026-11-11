#include <bits/stdc++.h>
using namespace std;
string s;
bool f;
void ch(int i, int j){
    for(int x = i;x <= i + j - 1;x++){
        if(s[x] != s[i + j - 1 - x + i]){
           return ;
        }
    }
    f = true;
    return ;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        int m;
        char c;
        cin >> m >> c;
        while(m--){
            s += c;;
        }
    }
    for(int i = 0;i < s.size();i++){
        for(int j = s.size() - i;j >= 1;j++){
            ch(i, j);
            if(f == true){
                cout << max(i, size() - i - j);
                return 0;
            }
        }
    }
    return 0;
}