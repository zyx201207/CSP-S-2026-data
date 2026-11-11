#include<bits/stdc++.h>
using namespace std;
string s,t;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A'&&s1[i]<='Z'){
            s=s1.substr(0,i-1);
            t=s2.substr(0,i-1);
            a=s1[i];b=s2[i];
        }
    }
    //cout<<a<<' '<<b<<'\n';
    if(s==t)cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if(a=='A'||a=='B'||a=='C'){
        if(b=='A'||b=='B'||b=='C')cout<<1;
        else {
            cout<<"00";
            return 0;
        }
    }
    else {
        if(b=='D'||b=='F')cout<<1;
        else {
            cout<<"00";
            return 0;
        }
    }
    int x=abs(int(a-b));
    if(x==1)cout<<1;
    else cout<<0;
    return 0;
}
