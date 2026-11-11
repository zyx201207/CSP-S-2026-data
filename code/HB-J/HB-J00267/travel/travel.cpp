#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s2[0]==s1[0]&&s2[1]==s1[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D')){
        cout<<1;
        return 0;
    }
    for(int i=0;i<3;i++){
        char c='A'+i;
        if(s1[2]==c&&(s2[2]==char(c-1)||s2[2]==char(c+1))){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
