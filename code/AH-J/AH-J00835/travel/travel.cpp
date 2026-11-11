#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f(string s1,string s2){
    if((s1=="A"||s1=="B"||s1=="C")&&(s2=="A"||s2=="B"||s2=="C")){
        return 1;
    }
    if((s1=="D"||s1=="E")&&(s2=="D"||s2=="E")){
        return 1;
    }
    return 0;
}
bool solve(string s1,string s2){
    if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="A")||(s1=="B"&&s2=="C")||(s1=="C"&&s2=="B")||(s1=="E"&&s2=="D")||(s1=="D"&&s2=="E")){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    string b1=b.substr(0,2);
    string b2=b.substr(2,1);
    string d1=d.substr(0,2);
    string d2=d.substr(2,1);
    bool ok=1;
    if(a!=c){
        cout<<0;
        ok=0;
    }else{
        cout<<1;
    }
    if(ok&&b1==d1){
        cout<<1;
    }else{
        cout<<0;
        ok=0;
    }
    if(ok&&f(b2,d2)){
        cout<<1;
    }else{
        cout<<0;
        ok=0;
    }
    if(ok&&solve(b2,d2)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
