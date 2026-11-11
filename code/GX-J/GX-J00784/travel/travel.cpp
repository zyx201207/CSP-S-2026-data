#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = s1.length()-1,a2 = s2.length()-1;
    if(c1 == c2){
        cout << '1';
    }else cout << '0';
    if(c1 == c2 && s1[0]+s1[1] == s2[0]+s2[1]){
        cout << '1';
    }else cout << '0';
    if(c1 == c2 && s1[0]+s1[1] == s2[0]+s2[1] && (s1[a1] <= 'C' && s2[a2] <= 'C')||((s1[a1] > 'C' && s2[a2] > 'C'))){
        cout << '1';
    }else cout << '0';
    if(c1 == c2 && s1[0]+s1[1] == s2[0]+s2[1] && (s1[a1] <= 'C' && s2[a2] <= 'C')||((s1[a1] > 'C' && s2[a2] > 'C')) && abs(s1[a1]-s2[a2]) == 1){
        cout << '1';
    }else cout << '0';
    return 0;
}
