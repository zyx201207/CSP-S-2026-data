#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1 = 0, c2 = 0, s1 = 0, s2 = 0;
    char ch1 = ' ', ch2 = ' ';
    char x;
    cin >> x;
    c1 += (x - '0') * 10;
    cin >> x;
    c1 += x - '0';
    cin >> x;
    s1 += (x - '0') * 10;
    cin >> x;
    s1 += x - '0';
    cin >> ch1;
    cin >> x;
    c2 += (x - '0') * 10;
    cin >> x;
    c2 += x - '0';
    cin >> x;
    s2 += (x - '0') * 10;
    cin >> x;
    s2 += x - '0';
    cin >> ch2;
    bool flag = true;
    if(c1 == c2){
        cout << 1;
    }else{
        flag = false;
        cout << 0;
    }
    if((s1 == s2) && flag){
        cout << 1;
    }else{
        flag = false;
        cout << 0;
    }
    if(((ch1 <= 'C' && ch2 <= 'C') || (ch1 >= 'D' && ch2 >= 'D'))&&flag){
        cout << 1;
    }else{
        flag = false;
        cout << 0;
    }
    if(flag && (max(ch1 - ch2, ch2 - ch1) == 1)){
        cout << 1;
    }else{
        flag = false;
        cout << 0;
    }
    return 0;
}
