#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2 ;
    if(c1 == c2){
        cout << 1 ;
    }
    else{
        cout << 0 ;
    }
    string t1 = s1.substr(0,2);
    string t2 = s2.substr(0,2);
    char p1 = s1[2];
    char p2 = s2[2];
    if(t1 == t1){
        cout << 1 ;
    }
    else{
        cout << 0 ;
    }
    if(p1 <= 'C' && p2 <= 'C' || p1 > 'C' && p2 > 'C'){
        cout << 1 ;
    }
    else{
        cout << 0 ;
    }
    if(p1 == 'C' && p2 == 'D' || p1 == 'D' && p2 == 'C' || abs(p1-p2) != 1){
        cout << 0 ;
    }
    else{
        cout << 1 ;
    }
    return 0;
}
