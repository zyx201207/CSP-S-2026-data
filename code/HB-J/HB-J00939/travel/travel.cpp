#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1!=c2){
        cout << "0000" << endl;
    }
    else{
        cout << 1;
        if(s1.substr(0, 2)!=s2.substr(0, 2)){
            cout << "000" << endl;
        }
        else{
            cout << 1;
            bool f1 = 0, f2 = 0;
            f1 = (s1[2]>='A'&&s1[2]<='C');
            f2 = (s2[2]>='A'&&s2[2]<='C');
            if(f1!=f2){
                cout << "00";
            }
            else{
                cout << 1;
                if(f1==1&&f2==1){
                    if(s1[2]=='B'||s2[2]=='B')
                        cout << 1 << endl;
                    else
                        cout << 0 << endl;
                }
                else{
                    cout << 1 << endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}