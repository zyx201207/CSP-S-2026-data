#include<string>
#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if(s1.at(2)=='A' || s1.at(2)=='B' || s1.at(2)=='C'){
                if(s2.at(2)=='A' || s2.at(2)=='B' || s2.at(2)=='C'){
                    cout<<1;
                    if(s1.at(2)>s2.at(2))swap(s1[2],s2[2]);
                    if(s1.at(2)=='A' && s2.at(2)=='B')cout<<1;
                    else if(s1.at(2)=='B' && s2.at(2)=='C')cout<<1;
                    else cout<<0;
                }else cout<<"00";
            }else if(s1.at(2)=='D' || s1.at(2)=='F'){
                if(s2.at(2)=='D' || s2.at(2)=='F')cout<<11;
                else cout<<"00";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}