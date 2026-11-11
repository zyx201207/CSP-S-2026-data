#include <bits/stdc++.h>
using namespace std;
string a,b,chuann,chua;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> chuann >> b >> chua;
    if (a != b){
        cout << "0000";
        return 0;
    }
    if (chuann[0]==chua[0]&&chuann[1]==chua[1]){
        if ((chuann[2]<='C'&&chuann[2]>='A')&&(chua[2]<='C'&&chua[2]>='A')){
            if (chuann[2]-'A' == chua[2]-'A'+1) cout << "1111";
            if (chuann[2]-'A'+1 == chua[2]-'A') cout << "1111";
            else cout << "1110";
        }
        else if ((chuann[2]<='F'&&chuann[2]>='D')&&(chua[2]<='F'&&chua[2]>='D')) cout << "1111";
        else cout << "1100";
    }
    else cout << "1000";
    return 0;
}
