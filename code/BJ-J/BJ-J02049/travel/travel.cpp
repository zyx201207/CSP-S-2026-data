#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    if(s1==s2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(c1[2]=='A'){
        if(c2[2]=='B'||c2[2]=='C'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
        if(c2[2]=='B'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(c1[2]=='B'){
        if(c2[2]=='A'||c2[2]=='C'){
            cout<<11;
        }else{
            cout<<"00";
            return 0;
        }
    }
    if(c1[2]=='C'){
        if(c2[2]=='B'||c2[2]=='A'){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
        if(c2[2]=='B'){
            cout<<1;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(c1[2]=='D'){
        if(c2[2]=='F'){
            cout<<11;
        }else{
            cout<<"00";
            return 0;
        }
    }
    if(c1[2]=='F'){
        if(c2[2]=='D'){
            cout<<11;
        }else{
            cout<<"00";
            return 0;
        }
    }
    return 0;
}
