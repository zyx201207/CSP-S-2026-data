#include<iostream>
using namespace std;
int c1, c2;
string s1, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000" << endl;
        return 0;
    }
    else if(s1[0] != s2[0] || s1[1] != s2[1]){
        cout << "1000" << endl;
        return 0;
    }
    else{
        char cc1 = s1[2], cc2 = s2[2];
        if('A' <= cc1 && cc1 <= 'C'){
            if('A' <= cc2 && cc2 <= 'C'){
                if(abs(cc1-cc2) == 1)
                    cout << "1111" << endl;
                else
                    cout << "1110" << endl;
            }
            else
                cout << "1100" << endl;
        }
        else{
            if('D' <= cc2 && cc2 <= 'F'){
                if(abs(cc1-cc2) == 1)
                    cout << "1111" << endl;
                else
                    cout << "1110" << endl;
            }
            else
                cout << "1100" << endl;
        }
    }
    return 0;
}
