#include <bits/stdc++.h>
using namespace std;
char a[] = {'A','B','C'};
char b[] = {'D','F'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        for(int i = 1;i <= 4;i++) cout << 0;
        return 0;
    }
    bool fl = true;
    for(int i = 0;i < 2;i++){
        if(s1[i] != s2[i]){
            fl = false;
            break;
        }
    }
    if(fl){
        cout << 1;
    }
    else{
        for(int i = 1;i <= 3;i++) cout << 0;
        return 0;
    }
    int x1,x2;
    for(int i = 0;i < 3;i++){
        if(s1[2] == a[i]) x1 = 1;
        if(s2[2] == a[i]) x2 = 1;
    }
    for(int i = 0;i < 2;i++){
        if(s1[2] == b[i]) x1 = 2;
        if(s2[2] == b[i]) x2 = 2;
    }
    if(x1 == x2) cout << 1;
    else{
        for(int i = 1;i <= 2;i++) cout << 0;
        return 0;
    }
    if(s1[2] + 1 == s2[2] || s2[2] + 1 == s1[2]) cout << 1;
    else cout << 0;
    return 0;
}
