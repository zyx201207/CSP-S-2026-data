#include<iostream>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int q=0,w=0,cca=0,ccb=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ccb=1;
    cout<<ccb;
    if(ccb==1){
        if(s1[0]+s1[1]==s2[0]+s2[1])cca=1;
        cout<<cca;
        if(cca==1){
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    q=1;
                }
            }
            if(s1[2]=='D'||s1[2]=='F'){
                if(s2[2]=='D'||s2[2]=='F'){
                    q=1;
                }
            }
            cout<<q;
            if(s1[2]=='A'&&s2[2]=='B')w=1;
            if(s1[2]=='B'&&s2[2]=='C')w=1;
            if(s1[2]=='D'&&s2[2]=='F')w=1;
            if(s1[2]=='B'&&s2[2]=='A')w=1;
            if(s1[2]=='C'&&s2[2]=='B')w=1;
            if(s1[2]=='F'&&s2[2]=='D')w=1;
            cout<<w;
        }
        else cout<<0<<0;
    }
    else cout<<0<<0<<0;
    return 0;
}
