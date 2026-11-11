#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1 >>s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
    }else{
        cout <<0;
    }
    string ph1=s1.substr(0,2),ph2=s2.substr(0,2);
    if(c1==c2 && ph1==ph2){
        cout <<1;
    }else{
        cout << 0;
    }
    if(c1==c2 && ph1==ph2 && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' &&s2[2]>'C'))){
        cout << 1;
    }else{
        cout << 0;
    }
    if(c1==c2 && ph1==ph2 && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' &&s2[2]>'C')) && ((abs(int(s2[2]-s1[2]))==1 && (s1[2]<='C' && s2[2]<='C')) || (abs(int(s2[2]-s1[2]))==2 && (s1[2]>'C' &&s2[2]>'C')))){
        cout << 1;
    }else{
        cout <<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

