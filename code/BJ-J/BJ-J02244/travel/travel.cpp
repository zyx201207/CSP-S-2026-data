#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int s1_num,s2_num,s2_word,s1_word;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    s1_num=(s1[0]-'0')*10+(s1[1]-'0');
    s2_num=(s2[0]-'0')*10+(s2[1]-'0');
    if(s1_num==s2_num){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    s1_word=s1[2]-'A';
    s2_word=s2[2]-'A';
    if(s1_word<3&&s2_word<3){
        cout<<"1";
        if(s1_word-s2_word==1||s2_word-s1_word==1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else if(s2_word>=3&&s1_word>=3){
        cout<<"11";
    }else{
        cout<<"00";
        return 0;
    }
    return 0;
}