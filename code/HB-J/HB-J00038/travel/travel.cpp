#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    if (a==c){
        cout << "1";
        char b1=b[0],b2=b[1];
        char d1=d[0],d2=d[1];
        if (b1==d1&&b2==d2){
            cout << "1";
            char b3=b[2];
            char d3=d[2];
            int sizeb=b3-'A';
            int sized=d3-'A';
            if ((sizeb>=0&&sizeb<=2)&&(sized>=0&&sized<=2)||(sizeb>=3&&sizeb<=4)&&(sized>=3&&sized<=4)){
                cout << "1";
                if (abs(sizeb-sized)<=1){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
