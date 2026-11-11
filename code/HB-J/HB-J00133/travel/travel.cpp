#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int cnt = 4;
    if(c1 == c2){
        cout << 1;
        cnt--;
        if(s1.substr(0,2) == s2.substr(0,2)){
            cout << 1;
            cnt--;
            char a = s1[2], b = s2[2];
            if(a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D'){
                cout << 1;
                cnt--;
                if(a + 1 == b || b + 1 == a){
                    cout << 1;
                    cnt--;
                }
            }
        }
    }
    for(int i = cnt; i >= 1; i--){
        cout << 0;
    }
    return 0;
}
