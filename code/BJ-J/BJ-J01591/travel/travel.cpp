#include<bits/stdc++.h>
using namespace std;
int x, y;
string a, b;
string ans = "";
int sy[130];
void solve(){
    sy['A'] = 1;
    sy['B'] = 1;
    sy['C'] = 1;
    sy['D'] = 2;
    sy['F'] = 2;
    ans = "0000";
    if(x==y){
        ans[0] = '1';
    }else{
        return;
    }
    int p=0, q=0;
    char v, w;
    p = (a[0]-'0') * 10 + a[1];
    q = (b[0] - '0' ) * 10 + b[1];
    v = a[2];
    w = b[2];
    if(p==q){
        ans[1] = '1';
    }else {
        return;
    }
    if(sy[v] == sy[w] && sy[v] != 0){
        ans[2] = '1';
    }else return;
    if(v > w) swap(v,w);
    if(v=='D'&&w=='F' || v=='A' && w=='B' || v=='B'&&w=='C'){
        ans[3] = '1';
    }
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    
    // x-a, y-b;
    cin >> x >> a >> y >> b;
    solve();
    cout << ans << endl;
    
    return 0;
}