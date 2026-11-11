#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans = 0;
    cin >> n;
    string s;
    for(long long i = 1;i <= n;i ++){
        int ai;
        string ci;
        cin >> ai >> ci;
        for(int j = 1;j <= ai;j ++) s += ci;
    }
    int len = s.size();
    for(int i = 0;i < len / 2;i ++){
        if(s[i] != s[len - i - 1]) ans ++;
    }
    cout << ans;
    return 0;
}

