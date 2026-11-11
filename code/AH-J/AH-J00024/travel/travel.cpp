#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    string w="";
    string s="";
    w+=s1[0];
    w+=s1[1];
    s+=s2[0];
    s+=s2[1];
    cout<<((c1==c2)&&(w==s));
    bool flag=true;
    if(((s1[2]=='D'||s1[2]=='F')&&((s2[2]=='A'||s2[2]=='B')||s2[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&((s1[2]=='A'||s1[2]=='B')||s1[2]=='C'))){
        flag=false;
    }
    cout<<((c1==c2)&&(w==s)&&(flag));
    bool has2=((c1==c2)&&(w==s)&&(flag));
    int x=s1[2]-'0';
    int y=s2[2]-'0';
    if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D')&&s1[2]=='F'){
        cout<<(has2);
        return 0;
    }
    if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
        cout<<0;
        return 0;
    }
    if(abs(x-y)!=1){
        cout<<0;
        return 0;
    }else{
        cout<<(has2);
        return 0;
    }
    return 0;
}
