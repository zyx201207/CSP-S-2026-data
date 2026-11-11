#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f(char a,char b){
    if(a=='A'&&b=='B'||b=='A'&&a=='B'){
        return 1;
    }
    else if(a=='B'&&b=='C'||b=='B'&&a=='C'){
        return 1;
    }
    else if(a=='D'&&b=='F'||b=='D'&&a=='F'){
        return 2;
    }
    else{
        return 0;
    }
}
bool x(char a,char b){
    if(a=='A'&&b=='C'||a=='C'&&b=='A'){
        return 0;
    }
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(c1==c2){
        cout<<1;
        if(s2[0]==s1[0]&&s2[1]==s1[1]){
            cout<<1;
            if(f(s1[2],s2[2])==1){
                cout<<1;
            }
            else if(f(s1[2],s2[2])==2){
                cout<<1<<1;
                return 0;
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        else{
            cout<<0<<0<<0;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    cout<<x(s1[2],s2[2]);
    return 0;
}
