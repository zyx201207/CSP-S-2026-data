#include<bits/stdc++.h>
using namespace std;
string s1[];
string c1[];
string s2[];
string c2[];

int main(){
    feopen("travel.in","w",std);
    feopen("travel.out","r",std);
    cin>>s1>>c1>>s2>>c2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }

    if((s1[2]=="A"&&s2[2]=="B")||(s1[2]=="B"&&s2[2]=="A")||(s1[2]=="B"&&s2[2]=="C")||(s1[2]=="C"&&s2[2]=="B")||(s1[2]=="D"&&s2[2]=="F")||(s1[2]=="F"&&s2[2]=="D")){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((s1[2]=="A"&&s2[2]=="B")||(s1[2]=="B"&&s2[2]=="A")||(s1[2]=="B"&&s2[2]=="C")||(s1[2]=="C"&&s2[2]=="B")||(s1[2]=="D"&&s2[2]=="F")||(s1[2]=="F"&&s2[2]=="D")||(s1[2]=="C"&&s2[2]=="A")||(s1[2]=="A"&&s2[2]=="C")){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
