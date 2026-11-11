#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    int x=c2[2]-'A';
    int y=s2[2]-'A';
    if(x==3||x==5){
        x+=2;
    }
    if(y==5||y==3){
        y+=2;
    }
    if(c1==s1){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(c1==s1&&c2[0]==s2[0]&&c2[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if(abs(x-y)<=2){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((s2[2]=='F'&&c2[2]=='D')||s2[2]=='D'&&c2[2]=='F'){
        cout<<"1";
    }else{
        if(abs(x-y)==1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }

    return 0;
}
