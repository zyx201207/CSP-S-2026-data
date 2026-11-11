#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string s1, s2, s3, s4;

    char c1, c2, c3, c4;

    cin >> s1 >> s2 >> s3 >> s4;

    if(s1[0] == s3[0] && s1[1] == s3[1]){
        c1 = '1';
        if(s2[0] == s4[0] && s2[1] == s4[1]){
            c2 = '1';
            if(s2[2] == 'A' && s4[2] == 'B' || s2[2] == 'A' && s4[2] == 'C' || s2[2] == 'B' && s4[2] == 'A' || s2[2] == 'B' && s4[2] == 'C' || s2[2] == 'C' && s4[2] == 'A' || s2[2] == 'C' && s4[2] == 'B' || s2[2] == 'D' && s4[2] == 'F' || s2[2] == 'F' && s4[2] == 'D'){
                c3 = '1';
                if(s2[2] == 'A' && s4[2] == 'B' || s2[2] == 'B' && s4[2] == 'A' || s2[2] == 'B' && s4[2] == 'C' || s2[2] == 'C' && s4[2] == 'B' || s2[2] == 'D' && s4[2] == 'F' || s2[2] == 'F' && s4[2] == 'D'){
                    c4 = '1';
                }
            }
            else{
                c3 = '0';
                c4 = '0';
            }
        }
        else{
            c2 = '0';
            c3 = '0';
            c4 = '0';
        }
    }
    else{
        c1 = '0';
        c2 = '0';
        c3 = '0';
        c4 = '0';
    }

    cout << c1 << c2 << c3 << c4;



    return 0;

}
