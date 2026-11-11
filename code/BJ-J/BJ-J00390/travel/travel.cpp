#include<bits/stdc++.h>
using namespace std;
string a1,a2,a3,b1,b2,b3;
char a4,b4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        return 0;
   }
    cout<<"1";
    for(int i=0;i<2;i++){
        a3+=a2[i];
    }
    for(int i=0;i<2;i++){
        b3+=b2[i];
    }
    if(a3!=b3){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    a4=a2[2];
    b4=b2[2];
    if(a4<b4)swap(a4,b4);
    if((a4=='D'||a4=='E')&&(b4=='A'||b4=='B'||b4=='C')){
        cout<<"00";
        return 0;
    }else if(int(a4-b4)>1){
        cout<<"10";
        return 0;
    }else{
        cout<<"1";
        cout<<"1";
    }
    return 0;
}
