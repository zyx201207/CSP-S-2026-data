#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char b1,b2;
    int c1,c2,s1,s2;
    cin >> c1 >> s1 >> b1 >> c2 >> s2 >> b2;
    bool f1 = (b1 == 'D') || (b1 == 'F');
    bool f2 = (b2 == 'D') || (b2 == 'F');
    if(c1 == c2){
        if(s1 == s2){
            if(f1 == f2){
                if(f1 == 1 || b1 == 'B' || b2 == 'B')
                    cout << "1111";
                else
                    cout << "1110";
            }
            else
                cout << "1100";
        }
        else
            cout << "1000";
    }
    else
        cout << "0000";
    return 0;
}
