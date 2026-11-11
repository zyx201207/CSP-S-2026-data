#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
string a, b, c, d;
bool m, n;
int main(){

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 != c2){
        cout << "0000" << endl;
        return 0;
    }
    cout << "1";

    for (int i = 0; i < 2; i++){
        a += s1[i];
    }
    for (int i = 0; i < 2; i++){
        b += s2[i];
    }
    if (a != b){
        cout << "000" << endl;
        return 0;
    }
    cout << "1";

    c = s1[2], d = s2[2];
    if (c == "A" || c == "B" || c == "C"){
        m = true;
    } else{
        m = false;
    }
    if (d == "A" || d == "B" || d == "C"){
        n = true;
    } else{
        n = false;
    }
    if (m != n){
        cout << "00" << endl;
        return 0;
    }
    cout << "1";

    if (m == false){
        cout << "1" << endl;
        return 0;
    } else if (c != "B" && d != "B"){
        cout << "0" << endl;
        return 0;
    } else{
        cout << "1" << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
