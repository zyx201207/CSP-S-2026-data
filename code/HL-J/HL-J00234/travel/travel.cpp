#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ansa,ansb,ansc,ansd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
//    02 01A 02 01B
//    1111
    cin >>c1 >> s1 >> c2 >> s2;
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            cout << "0000";
            return 0;
        }
    }
    ansa=1;
    cout << ansa;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
           cout <<"000";
            return 0;
        }
    }
    ansb=1;
    cout << ansb;
    if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C'){
        ansc=1;
        cout << ansc;
    }else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
        ansc=1;
        cout << ansc;

    }else{
        cout << "00";
        return 0;
    }
    if(s1[2]+1==s2[2] || s2[2]+1==s1[2]){
        ansd=1;
        cout << ansd;
    }else{
        cout <<'0';
    }

    return 0;
}
