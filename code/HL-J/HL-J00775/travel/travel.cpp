#include <iostream>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_studio(false);
    cin.(nullptr);
    //freopen("travel.in","r");
    //freopen("travel.out","w");

    string a1,b1,a2,b2;
    int i,j,rz,xz,ry,xy,rl,xl;

    if(a1==a2) cout<<'1';
    else {
        cout<<'0000';
        return 0;
    }

    int l1=getline(cin.b1);
    int l2=getline(cin.b2);

    for(i=1;i<l1;i+=2){
        rz=(b1[i]-'0')+(b1[i-1]-'0')*10;
    }
    for(i=1;i<l2;i++){
        kz=(b2[i]-'0')+(b2[i-1]-'0')*10;
    }
    if(rz==kz) cout<<'1';
    else{
        cout<<'000';
        return 0;
    }

    for(i=2;i<l1;i++){
        if('A'<=b1[i]) ry=1;
        else ry=0;
    }
    for(i=2;i<l2;i++){
        if('A'<=b2[i]) xy=1;
        else xy=0;
    }
    if(ry==xy) cout<<'1';
    else{
        cout<<'00';
        return 0;
    }

    for(i=2;i<l1;i++){
        ry=b1[i]-'A';
    }
    for(i=2;i<l2;i++){
        xy=b2[i]-'A';
    }
    if(ry==xy) cout<<'1';
    else{
        cout<<'0';
        return 0;
    }
}
