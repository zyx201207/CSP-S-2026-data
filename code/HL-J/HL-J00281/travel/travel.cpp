#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char k1 = s1[2],k2 = s2[2];
    int m1 = (k1=='A' || k1=='B' || k1=='C');
    int m2 = (k2=='A' || k2=='B' || k2=='C');
    if(m1 == m2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(k1-k2)==1){
        cout<<1;
    }else{
        cout<<"0";
    }
}

