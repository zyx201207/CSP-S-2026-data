#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string h1=s1.substr(0,2),h2=s2.substr(0,2);
    char p1=s1[2],p2=s2[2];
    if(p1>p2){
        char tmp=p1;
        p1=p2;
        p2=tmp;
    }
    //cout<<p1<<p2;
    if(c1==c2){
        cout<<"1";
        if(h1==h2){
            cout<<"1";
            if(p1=='A'&&p2=='B'||p1=='B'&&p2=='C'||p1=='D'&&p2=='F'){
                cout<<"11";
            }
            else if(p1=='A'&&p2=='C'){
                cout<<"10";
            }
            else{
                cout<<"00";
            }
        }
        else{cout<<"000";}
    }
    else{
        cout<<"0000";
    }
    return 0;
}
