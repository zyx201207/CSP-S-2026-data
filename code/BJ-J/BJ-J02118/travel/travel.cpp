#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    for(int i=0;i<c1.size();i++){
        if(c1[i]!=c3[i]){
        cout<<"0000";
        return 0;
        }
    }
    cout<<"1";
    for(int i=0;i<2;i++){
        if(c2[i]!=c4[i]){
        cout<<"000";
        return 0;
        }
    }
    cout<<"1";
    if((c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]>='D'&&c2[2]<='F'&&c4[2]>='D'&&c4[2]<='F')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(c2[2]=='A'&&c4[2]=='C'||c2[2]=='C'&&c4[2]=='A'){
        cout<<"0";
    }else{
        cout<<"1";
    }

    return 0;
}
