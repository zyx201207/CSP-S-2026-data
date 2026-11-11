#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        if((s1[0]-'0')*10+s1[1]-'0' == (s2[0]-'0')*10+s2[1]-'0'){
            cout << 1;
            if(s1[2] <= 'C' && s2[2] <= 'C' || (s1[2] >= 'D'&&s2[2] >= 'D')){
                cout << 1;
                string a;
                if(s1 > s2){
                    a = s2;
                    s2 = s1;
                    s1 = a;
                }
                if(s1[2] == 'A' && s2[2] == 'B' || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F'))
                    cout << 1;
                else cout << 0;
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    return 0;
}
