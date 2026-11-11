#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    bool s1_,s2_,_1=0,_2=0,_3=0,_4=0;
    cin >> c1 >> s1 >> c2 >> s2;
    s1_=(s1[2]=='D'||s1[2]=='F');
    s2_=(s2[2]=='D'||s2[2]=='F');

    if(c1==c2){
        _1=1;
        if( s1[0]==s2[0] && s1[1]==s2[1] ){
            _2=1;
            if(s1_==s2_){
                _3=1;
                if( (s1_&&s2_) || !(s1[2]!='B'&&s2[2]!='B') ){
                    _4=1;
                }
            }
        }
    }
    cout << _1 << _2 << _3 << _4;
    return 0;
}
