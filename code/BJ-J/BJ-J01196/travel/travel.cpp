#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c){
        int x = int(b[0]-'0')*10+int(b[1]-'0');
        int y = int(d[0]-'0')*10+int(d[1]-'0');
        if(x == y){
            char xx = b[2],yy = d[2];
            if('A' <= xx && xx <= 'C' && 'A' <= yy && yy <= 'C'){
                //if(xx > yy) swap(xx,yy);
                if(xx == 'A' && yy == 'C') cout << "1110" << endl;
                else if(xx == 'C' && yy == 'A') cout << "1110" << endl;
                else cout << "1111" << endl;
            }
            else if(xx == 'D' && yy == 'F' || xx == 'F' && yy == 'D')
                cout << "1111" << endl;
            else cout << "1100" << endl;
        }
        else cout << "1000" << endl;
    }
    else cout << "0000" << endl;


    return 0;
}
