#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int s;
bool p(char a,char b){
    if(a=='A'&&(b=='B'||b=='C')){
        if(b=='B')s=1;
        return 1;
    }
    if(a=='B'&&(b=='A'||b=='C')){
        s=1;
        return 1;
    }
    if(a=='C'&&(b=='B'||b=='A')){
        if(b=='B')s=1;
        return 1;
    }
    if(a=='D'&&b=='F'){
        s=1;
        return 1;
    }
    if(a=='F'&&b=='D'){
        s=1;
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
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(p(s1[2],s2[2])){
                cout<<1;
                if(s)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
