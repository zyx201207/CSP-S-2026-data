#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool f0 = 1 , f1 = 1 , f2 = 1;
    char ch1 = s1[2] , ch2 = s2[2];
    //1
    if(c1 == c2){
        cout << 1;
    }else{
        f0 = f1 = f2 = 0;
        cout << 0;
    }
    //2
    if(f0){
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
        }else{
            f1 = f2 = 0;
            cout << 0;
        }
    }else{
        cout << 0;
    }

    //3
    if(f1){
        if((ch1 >= 'A' && ch1 <= 'C' && ch2 >= 'A' && ch2 <= 'C') || ((ch1 == 'D' || ch1 == 'F') && (ch2 == 'D' || ch2 == 'F'))){
            cout << 1;
        }else{
            f2 = 0;
            cout << 0;
        }
    }else{
        cout << 0;
    }
    //4
    if(f2){
        if((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && (ch2 == 'A' || ch2 == 'C') || (ch1 == 'C' && ch2 == 'B'))){
            cout << 1;
        }else if((ch1 == 'D' && ch2 == 'F') || ch1 == 'F' && ch2 == 'D'){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }
    cout << "\n";
    return 0;
}
