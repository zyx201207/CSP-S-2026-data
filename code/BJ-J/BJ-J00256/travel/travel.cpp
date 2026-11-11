#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;cin >> c1;
    string s1,s2;cin >> s1 >> c2 >> s2;
    int z1=(s1[0]-'0') * 10 + (s1[1]-'0');
    int z2=(s2[0]-'0') * 10 + (s2[1]-'0');
    int h1=s1[2]-'A'+1;
    int h2=s2[2]-'A'+1;
    if(c1==c2){
        cout << 1;
        if(z1==z2){
            cout << 1;
            if(h1 <= 3 && h2<=3 || h1 > 3 && h2 > 3){
                cout << 1;
                if(abs(h1-h2)==1 || h1==4 && h2 == 6 || h2==4 && h1==6){
                    cout << 1;
                }else {
                    cout << 0;
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
        return 0;
    }
    return 0;
}
