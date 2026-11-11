#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool o1=0,o2=0,o3=0,o4=0;
    if((c1[0]==c2[0])&&(c1[1]==c2[1])){
        o1=1;
    }
    if(o1){
        if((s1[0]==s2[0])&&(s1[1]==s2[1])){
            o2=1;
        }
    }
    if(o2){
        if((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C')){
            if((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')){o3=1;}
        }else{
            if((s2[2]=='D')||(s2[2]=='F')){o3=1;}
        }
    }
    if(o3){
        if(s1[2]=='A'){
            if(s2[2]=='B'){o4=1;}
        }else if(s1[2]=='B'){
            if((s2[2]=='A')||(s2[2]=='C')){o4=1;}
        }else if(s1[2]=='C'){
            if(s2[2]=='B'){o4=1;}
        }else if(s1[2]=='D'){
            if(s2[2]=='F'){o4=1;}
        }else if(s1[2]=='F'){
            if(s2[2]=='D'){o4=1;}
        }
    }
    cout << o1 << o2 << o3 << o4;
    return 0;
}
