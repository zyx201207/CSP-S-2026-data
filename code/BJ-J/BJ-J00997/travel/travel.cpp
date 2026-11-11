#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int len;
bool flag=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flag=0;
        }
    }
    if(flag){
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    char se1=s1[2];
    char se2=s2[2];
    flag=1;
    if((se1<='C'&&se2<='C')||(se1>='D'&&se2>='D')){
        cout << "1";
    }
    else{
        cout << "00";
        return 0;
    }
    if(se1==se2+1||se2==se1+1){
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
