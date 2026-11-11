#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
char r,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    r=r2[2];
    x=x2[2];
    if(r1!=x1){
        cout<<"0000";
    }else if((r2[0]!=x2[0])||(r2[1]!=x2[1])){
        cout<<"1000";
    }else if((r<='C'&&x>'C')||(x<='C'&&r>'C')){
        cout<<"1100";
    }else if((r=='A'&&x=='C')||(x=='A'&&r=='C')){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
