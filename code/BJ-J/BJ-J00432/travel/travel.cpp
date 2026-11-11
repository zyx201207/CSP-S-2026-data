#include<bits/stdc++.h>
using namespace std;
bool pai(string s,string ss){
    for(int i=0;i<s.size()-1;i++){
        if(s[i]!=ss[i]){
            return false;
        }
    }
    return true;
}
bool ai(string s,string ss){
    int s1=s[2]-'A';
    int s2=ss[2]-'A';
    if((s[2]=='C'&&ss[2]=='D')||(s[2]=='D'&&ss[2]=='C')){
        return false;
    }

    if(abs(s1-s2)==1){
        return true;
    }else{
        return false;
    }

}
bool ce(string s,string ss){
    int s1=s[2]-'A';
    int s2=ss[2]-'A';
    if((s[2]=='C'&&ss[2]=='D')||(s[2]=='D'&&ss[2]=='C')){
        return false;
    }

    if(abs(s1-s2)<=2){
        return true;
    }else{
        return false;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&pai(s1,s2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c2&&pai(s1,s2)&&ce(s1,s2)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&pai(s1,s2)&&ai(s1,s2)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
