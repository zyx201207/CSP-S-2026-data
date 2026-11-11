#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c2[0]==c4[0]&&c2[1]==c4[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    bool flag=false;
    if('A'<=c2[2]<='C'&&'A'<=c4[2]<='C'||'D'<=c2[2]<='E'&&'D'<=c4[2]<='F'){
        cout<<1;
        flag=true;
    }else{
        cout<<0;
    }
    if(flag){
        if(c2[2]=="D"){
            if(c4[2]=="F"){
               cout<<1;
            }else{
               cout<<0;
            }
        }else if(c4[2]=="D"){
            if(c2[2]=="F"){
               cout<<1;
            }else{
               cout<<0;
            }
        }else if(c2[2]+1==c4[2]||c2[2]-1==c4[2]){
            cout<<1;
        }else{
          cout<<0;
        }
    }else{
      cout<<0;
    }
    return 0;
}
