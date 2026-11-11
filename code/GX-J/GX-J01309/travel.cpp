#include <bits/stdc++.h>
using namespace std;
char C1[2],S1[3],C2[2],S2[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>C1[2]>>S1[3]>>C2[2]>>S2[3];
    if(C1[0]==C2[0]||C1[1]==C2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(S1[0]==S2[0]||S1[1]==S2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(S1[1]==S2[1]+1&&S1[1]==S2[1]-1||S2[1]==S1[1]-1&&S2[1]==S1[1]+1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
return 0;
}
