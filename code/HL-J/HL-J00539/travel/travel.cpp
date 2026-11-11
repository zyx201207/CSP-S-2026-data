#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1==c2)
    {
        cout << "1";
    }
    if(s1.substr(0,2)==s2.substr(0,2))
    {
        cout << "1";
        char a=s1[2],b=s2[2];
        if(a<='c'&& b<='c'|| a>='D' && b>='0')
        {
            cout << "0";
            if(abs(a-b)==1) cout << "1";
            else cout << "0";
        }
        else cout << "00";
    }
    else cout << "000";

    return 0;
}
