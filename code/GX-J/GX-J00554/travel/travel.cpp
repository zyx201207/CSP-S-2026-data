#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n1,n2,x1,x2,s="";
    cin >> n1 >> n2 >> x1 >> x2;
    if ((n1[0] == x1[0]) && (n1[1] == x1[1])){
        s += "1";
        if ((n2[0] == x2[0]) && (n2[1] == x2[1])){
            s += "1";
            if ((n2[2] == 'A' || n2[2] == 'B' || n2[2] == 'C') && (x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C')){
                s += "1";
                if (!((n2[2] == 'A' && x2[2] == 'C') || (n2[2] == 'C' && x2[2] == 'A'))) s += "1";
                else s += "0";
            }
            else if ((n2[2] == 'D' && x2[2] == 'F') || (n2[2] == 'F' && x2[2] == 'D')) s += "11";
            else s += "00";
        }
        else s += "000";
    }
    else s += "0000";
    cout << s;
    return 0;
}
