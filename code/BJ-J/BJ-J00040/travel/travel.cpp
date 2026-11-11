#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    cout << 1;
    string t1 = "",t2= "";
    t1+=s1[0];
    t1+=s1[1];
    t2+=s2[0];
    t2+=s2[1];
    if(t1 == t2){
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    char a = s1[2];
    char b = s2[2];
    if(((a >= 'A' && a <= 'C') && (b >= 'A'&& b <='C')) || ((a >= 'D' && a <= 'F') && (b >= 'D'&& b <='F')))
    {
        cout << 1;
    }
    else
    {
        cout << "00";
        return 0;
    }
    string k = "";
    k += a;
    k+= b;
    if(k == "AB" || k == "BA" || k == "BC" || k == "CB" || k == "DF" || k == "FD"){
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}
