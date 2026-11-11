#include<bits/stdc++.h>
using namespace std;
int n,cnt;
char c;
string s;
bool check(string r){
    string t = r;
    reverse(r.begin(),r.end());
    if(t == r) return true;
    else return false;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x = 0;
        cin >> x >> c;
        for(int j = 1;j <= x;j++){
            s += c;
        }
    }
    if(check(s)){
        cout << 0;
        return 0;
    }
    for(int i = 0;i <= s.size() - 1;i++){
        if(s[i] != s[s.size() - i - 1]){
            cnt++;
        }
    }
    cout << cnt / 2;
    return 0;
}
