#include<bits/stdc++.h>
using namespace std;
string s;
bool hw(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s == s1;
}
long long sum;
vector<int> v;
bool flag = 0;
string s2;
void work(){
    int n;
    string s1;
    cin >> n >> s1;
    sum += 1ll * n;
    v.push_back(n);
    s2 += s1;
    if(sum >= 1000000000){
        flag = 1;
    }else{
        while(n--){
            s += s1;
        }
    }

}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        work();
    }

    if(flag == 1){
        long long cnt = 0;
        for(int i = 0; i < ((int)s2.size()) / 2; i++){
            if(s2[i] != s2[(int)s2.size() - i - 1]){
                cnt += min(v[i] , v[(int)s2.size() - i - 1]);
            }
        }
        cout << cnt;
        return 0;
    }
    if(hw(s)){
        cout << 0;
        return 0;
    }
    long long cnt = 0;
    for(int i = 0; i < ((int)s.size()) / 2; i++){
        if(s[i] != s[(int)s.size() - i - 1]){
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
//68
