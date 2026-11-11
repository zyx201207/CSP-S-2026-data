#include <bits/stdc++.h>
#define int long long
using namespace std;
deque<pair<int, char> > kevin;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s;
    pair<int, char> now;
    pair<int, char> asd;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> asd.first >> asd.second;
        kevin.push_back(asd);
    };
    int ans = 0;
    bool qq = true;
    now = kevin.back();
    kevin.pop_back();
    while(!kevin.empty()){
        pair<int, char> teemp;
        if(qq){
            teemp = kevin.front();
            kevin.pop_front();
        }else{
            teemp = kevin.back();
            kevin.pop_back();
        };
        if(now.second == teemp.second){
            now.first -= teemp.first;
            if(now.first < 0) qq = (!qq);
            now.first = abs(now.first);
            continue;
        };
        if(now.first < teemp.first){
            swap(now, teemp);
            qq = (!qq);
        };
        now.first -= teemp.first;
        ans += teemp.first;
    };
    cout << ans;
};
