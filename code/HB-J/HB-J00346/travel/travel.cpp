#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>b1>>a2>>b2;
    if(a1==a2){
        cout<<1;
    }
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    int flag=0;
    for(int i=0;i<2;i++){
        if(b1[i]!=b2[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<1;
    }
    if(flag==1){
        cout<<"000";
        return 0;
    }
    if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
        cout<<1;
        if(b1[2]==b2[2]+1||b1[2]==b2[2]-1){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    if((b1[2]=='D'||b1[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
        cout<<1;
        if(b1[2]==b2[2]+1||b1[2]==b2[2]-1){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    cout<<"00";
    return 0;
}
