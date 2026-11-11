#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,c1;
    string d,d1;
    cin>>c>>c1>>d>>d1;
    if(c==d){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c1[0]!=d1[0]||c1[1]!=d1[1]){
        cout<<"000";
        return 0;
    }else{
        cout<<1;
    }
    if(c1[2]>='A'&&c1[2]<='C'&&d1[2]>='A'&&d1[2]<='C'){
            cout<<1;
    }else if(c1[2]>='D'&&c1[2]<='F'&&d1[2]>='D'&&d1[2]<='F'){
        cout<<1;
    }else{
        cout<<0;
    }
    if((c1[2]=='C'&&d1[2]=='D')||(c1[2]=='D'&&d1[2]=='C')){
        cout<<0;
    }else{
        if(c1[2]-d1[2]==1||d1[2]-c1[2]==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
