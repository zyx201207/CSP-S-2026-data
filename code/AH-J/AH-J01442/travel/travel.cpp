#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        LL r1=s1[0]-'0'+s1[1]-'0',x1=s2[0]-'0'+s2[1]-'0';
        if(r1==x1){
            cout<<"1";
            char r2=s1[2],x2=s2[2];
            if(r2<='C'&&x2<='C'){
                cout<<"1";
                if((r2=='A'&&x2=='C')||(r2=='C'&&x2=='A')){cout<<"0\n";}
                else{cout<<"1\n";}
            }
            else if(r2>='D'&&x2>='D'){cout<<"11\n";}
            else{cout<<"00\n";}
        }
        else{cout<<"000\n";}
    }
    else{cout<<"0000\n";}
    return 0;
}
