#include<bits/stdc++.h>
using namespace std;
string s_1,s_2,s_3,s_4;
bool cnt=0,cnt_1=0,cnt_2=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s_1>>s_2>>s_3>>s_4;
    if(s_1==s_3){
        cout<<"1";
        cnt_1=1;
    }
    else{
        cout<<"0";
    }
    if(cnt_1==0){
        cout<<"000";
        return 0;
    }
    if(s_2[0]==s_4[0] && s_2[1]==s_4[1]){
        cout<<"1";
        cnt=1;
    }
    else{
        cout<<"0";
    }
    if(cnt==0){
        cout<<"00";
        return 0;
    }
    else if((s_2[2]=='A' && s_4[2]=='B')||(s_2[2]=='A' && s_4[2]=='C')||(s_2[2]=='B' && s_4[2]=='C')||(s_2[2]=='D' && s_4[2]=='F')||(s_2[2]=='B' && s_4[2]=='A')||(s_2[2]=='B' && s_4[2]=='C')||(s_2[2]=='C' && s_4[2]=='A')||(s_2[2]=='C' && s_4[2]=='B')){
        cout<<"1";
        cnt_2=1;
    }
    else{
        cout<<"0";
    }
    if(cnt_2==0){
        cout<<"0";
        return 0;
    }
    if((s_2[2]=='A' && s_4[2]=='B')||(s_2[2]=='B' && s_4[2]=='C')||(s_2[2]=='C' && s_4[2]=='B')||(s_2[2]=='D' && s_4[2]=='F')||(s_2[2]=='B' && s_4[2]=='A')){
        cout<<"1";
    }
    else{
        cout<<"0";
    }


    return 0;
}
