#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,a1,a2;
    cin >> s1 >> s2 >> a1 >> a2;
    if(s1[0]==a1[0]&&s1[1]==a1[1]){
        if(s2[0]==a2[0]&&s2[1]==a2[1]){
            if((s2[2]<='C'&&a2[2]<='C')||(s2[2]>'C'&&a2[2]>'C')){
                if(abs(int(s2[2])-int(a2[2]))==1){
                    cout<<1111;
                    return 0;
                }
                cout<<1110;
                return 0;
            }
            cout<<1100;
            return 0;
        }
        cout<<1000;
        return 0;
    }
    cout<<"0000";
}
