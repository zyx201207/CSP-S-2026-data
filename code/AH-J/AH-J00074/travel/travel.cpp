#include <bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 ;
    for(int i=0;i<=2;i++){
        cin>>s1[i];
    }
    cin >> c2 ;
    for(int i=0;i<=2;i++){
        cin>>s2[i];
    }
    if(c1==c2) {
            cout << "1";
            if(s1[0]==s2[0]&&s1[1]==s2[1]) {
                    cout << "1";
                    cout << "1";
                    cout << "1";
            }
            else cout << "000";
    }
    else cout << "0000";
    return 0;
}
