#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
    string c1 , c2 , s1 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << 1;
            if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) {
                //cout << 8;
                cout << 1;
                //int d = (int(s1[0])-48) * 10 + int(s1[1]) - (int(s2[0])-48) * 10 - int(s2[1]);
                int d = abs(int(s1[2]) - int(s2[2]));
                //cout << d <<' ' << int(s1[2])<<' '<< int(s2[2])<< endl;
                if(d == 1 && ((s1[2] != 'C' && s2[2] != 'D') || (s2[2] != 'C' && s1[2] != 'D'))) {
                    cout << 1;
                }else {
                    cout << 0;
                }
            }else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
                //cout << 7;
                cout <<1;
                int d = abs(int(s1[2]) - int(s2[2]));
                if(d == 1 && ((s1[2] != 'C' && s2[2] != 'D') || (s2[2] != 'C' && s1[2] != 'D'))) {
                    cout << 1;
                }else {
                    cout << 0;
                }
            }else {

                cout << 0 << 0;
            }
        }else {
            cout << 0 <<0 <<0;
        }
    }else {
        cout << 0 <<0 <<0 <<0;
    }

}


