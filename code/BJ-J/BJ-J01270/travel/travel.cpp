#include<iostream>
#include<string>
using namespace std;
int r_c, x_c;
string r_s, x_s;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin >> r_c >> r_s >> x_c >> x_s;
    if(r_c == x_c){
        cout << '1';
        if(r_s[0] == x_s[0] && r_s[1] == x_s[1]){
            cout << '1';
            if(((r_s[2] == 'A' || r_s[2] == 'B' || r_s[2] == 'C') && (x_s[2]== 'A' || x_s[2] == 'B' || x_s[2] == 'C')) || ((r_s[2] == 'D' || r_s[2] == 'E') && (x_s[2]== 'D' || x_s[2] == 'E'))){
                cout << '1';
                if(r_s[2] == x_s[2] + 1 || x_s[2] == r_s[2] + 1) cout << '1';
                else cout << '0';
            }
            else cout <<"00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
