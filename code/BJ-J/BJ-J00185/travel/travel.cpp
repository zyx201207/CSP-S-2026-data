#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, z1, z2;
char z, x;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<s1.size()-1;i++){
        z1=z1+s1[i];
    }
    for(int i=0;i<s2.size()-1;i++){
        z2+=s2[i];
    }
    if(z1==z2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    z=s1[s1.size()-1];
    x=s2[s2.size()-1];
    if(z>'C'&&x>'C' || z<='C'&&x<='C'){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(z-x==1 || x-z==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
