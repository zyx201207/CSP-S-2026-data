#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, ans;
string s;
int a;
char c;
bool hw(string str){
    string s1;
    s1 = str;
    reverse(s1.begin(), s1.end());
    return s1 == str;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> c;
        while(a--){
            s += c;
        }
    }
    cout << s << "\n";
    if(hw(s)){
        cout << 0;
    }else{
        int siz = s.size();
        for(int i = 0; i <=  siz / 2; i++){
            if(s[i] != s[siz - i]){
                ans++;
            }
        }
        cout << ans;
    }
}
