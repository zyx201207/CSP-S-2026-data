#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
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
    char a,b;
    a=s1[2];b=s2[2];
    if(a=='A'){
        if(b=='B'||b=='C'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(a=='B'){
        if(b=='A'||b=='C'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(a=='C'){
        if(b=='A'||b=='B'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(a=='D'){
        if(b=='F'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(a=='f'){
        if(b=='D'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(a=='A'){
        if(b=='B'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(a=='B'){
        if(b=='A'||b=='C'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(a=='C'){
        if(b=='B'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(a=='D'){
        if(b=='F'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(a=='F'){
        if(b=='D'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}