#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
unordered_map<char,int> mp;
bool check() {
    char a=rs[rs.size()-1],b=xs[rs.size()-1];
    if(a > b) swap(a,b);
    if(a=='A' && b=='B') return true;
    if(a=='B' && b=='C') return true;
    if(a=='D' && b=='F') return true;
    return false;
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rs >> xc >> xs;
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    mp['D']=2;
    mp['F']=2;
    if(rc == xc) {
        cout << 1;
    } else {
        cout << 0;
    }
    if(rc == xc && rs.substr(0,2) == xs.substr(0,2)) {
        cout << 1;
    } else {
        cout << 0;
    }
    if(rc == xc && rs.substr(0,2) == xs.substr(0,2) && mp[rs[rs.size()-1]]==mp[xs[xs.size()-1]]) {
        cout << 1;
    } else {
        cout << 0;
    }
    if(rc == xc && rs.substr(0,2) == xs.substr(0,2) && mp[rs[rs.size()-1]]==mp[xs[xs.size()-1]] && check()) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
