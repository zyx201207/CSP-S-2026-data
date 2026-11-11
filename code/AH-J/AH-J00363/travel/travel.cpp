#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
string s1,s2,c1,c2;
int a,b,c,d;
char h1,h2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1){
        cout<<1;
        if(s2[0]==c2[0]&&s2[1]==c2[1]){
        cout<<1;
        }else{
            cout<<0;
        }
        if(s2[0]==c2[0]&&s2[1]==c2[1]){
            if(s2[2]=='A'&&c2[2]=='B'||s2[2]=='C'&&c2[2]=='B'||s2[2]=='B'&&c2[2]=='C'||s2[2]=='B'&&c2[2]=='A'||s2[2]=='A'&&c2[2]=='C'||s2[2]=='C'&&c2[2]=='A'||s2[2]=='D'&&c2[2]=='E'||s2[2]=='E'&&c2[2]=='D'){
                cout<<1;
            }else{
                cout<<0;
            }
            if(s2[2]=='A'&&c2[2]=='B'||s2[2]=='C'&&c2[2]=='B'||s2[2]=='B'&&c2[2]=='C'||s2[2]=='B'&&c2[2]=='A'||s2[2]=='D'&&c2[2]=='E'||s2[2]=='E'&&c2[2]=='D'){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
