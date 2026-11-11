//ok
#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int f(string s){
    int ans=0;
    switch(s[2]){
    case 'A':
    case 'B':
    case 'C':
        ans=0;
        break;
    default:
        ans=1;
        break;
    }
    return ans;
}

int g(string s1,string s2){
    if(f(s1)!=f(s2)){
        return 0;
    }
    if(f(s1)==0){
        if(s1[2]=='A'&&s2[2]=='B'){
            return 1;
        }
        if(s1[2]=='B'&&s2[2]=='C'){
            return 1;
        }
        return 0;
    }
    if(f(s1)==1){
        return 1;
    }
    return 0;
}

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
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(f(s1)==f(s2)){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(g(s1,s2)==1||g(s2,s1)==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
