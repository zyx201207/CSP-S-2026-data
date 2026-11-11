#include <bits/stdc++.h>
using namespace std;
struct ss{
    long long g;
    string m;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    vector<ss> s(n);
    for(int i = 0;i < n;++i){
        cin >> s[i].g >> s[i].m;
    }
    string S;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < s[i].g;++j){
            S += s[i].m;
        }
    }
    long long ans = 0;
    int len = S.size();
    int l = len / 2;
    for(int i = 0;i < l;++i){
        if(S[i] != S[len - i - 1]){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
