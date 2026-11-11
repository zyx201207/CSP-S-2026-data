#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int n, m;
    string s1, s2;
    cin >> n >> s1 >> m >> s2;
    if(n == m){
        cout << 1;
        if(s1[0] == s1[0] && s1[1] == s2[1]){
            cout << 1;
            if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
                cout << 1;
                if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'E') || (s1[2] == 'E' && s2[2] == 'D')){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else if((s1[2] == 'D' || s1[2] == 'E') && (s1[2] == 'E' || s1[2] == 'D')){
                cout << 11;
            }else{
                cout << 0 << 0;
            }

        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0 << 0;
    }


    return 0;
}
//100
