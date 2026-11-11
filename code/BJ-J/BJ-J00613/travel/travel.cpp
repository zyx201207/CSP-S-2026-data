#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int xiang=0;
    if(c1==c2){
        cout<<1;
        xiang=1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&xiang==1){
        cout<<1;
        xiang=2;
    }else{
        cout<<"000";
    }
    if(xiang==2){
        if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
            cout<<1;
            xiang=3;
        }else if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                cout<<1;
                xiang=4;
            }else{
                cout<<"00";
            }
        }else{
            cout<<"00";
        }
    }
    if(xiang==3){
        cout<<1;
    }else if(xiang==4){
        if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
