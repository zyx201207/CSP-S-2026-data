#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return ;
    }
    if(s1.first()==s2.first() && s1.second()==s2.second()){
        cout<<"1";
    }else{
        cout<<"000";
        return ;
    }
    if(s1.third()=="A"){
        if(s2.third()=="B") cout<<"11";
        else if(s2.third()=="C") cout<<"10";
        else cout<<"00";
    }else if(s1.third()=="B"){
        if(s2.third()=="A") cout<<"11";
        else if(s2.third()=="C") cout<<"11";
        else cout<<"00";
    }else if(s1.third()=="C"){
        if(s2.third()=="B") cout<<"11";
        else if(s2.third()=="A") cout<<"10";
        else cout<<"00";
    }else if(s1.third()=="D"){
        if(s2.third()=="F") cout<<"11";
        else cout<<"00";
    }else if(s1.third()=="F"){
        if(s2.third()=="D") cout<<"11";
        else cout<<"00";
    }
    return 0;
}