#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, s2, c1, c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2) {
        cout<<1;
    }
    else {
        cout<<"0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) {
        cout<<1;
    }
    else {
        cout<<"000";
        return 0;
    }

    int tmp1 = s1[2]-'A', tmp2 = s2[2]-'A';
    if((tmp1 < 3 && tmp2 < 3) || (tmp1 >= 3 && tmp2 >= 3)) {
        cout<<1;
    }
    else {
        cout<<"00";
        return 0;
    }
    // cout<<tmp1<<" "<<tmp2;
    if(abs(tmp1 - tmp2) <= 1) {
        cout<<1;
    }
    else {
        cout<<0;
    }
}