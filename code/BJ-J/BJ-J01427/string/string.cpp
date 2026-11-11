#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    //freopen("string2.in","r" ,stdin);
    //freopen("string2.out","w",stdout);
    int n;
    cin >> n;
    string s;
    bool f = false;
    int j = 1;
    int num = 0;
    char z;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        char c;
        cin >>c;
        num += x;
        if(c == z && j == 1) f = true;
        else j = 0,f = false;
        z = c;
        for(int j = 1;j <= x;j ++) s += c;
    }
    int ans = 0;
    if(!f) for(int i = 0;i < num;i ++) if(s[i] != s[num + 1 - i]) ans ++,cout <<s[i] << ' ' <<s[num + 1 - i];
    cout << ans << endl;
    return 0;
}
