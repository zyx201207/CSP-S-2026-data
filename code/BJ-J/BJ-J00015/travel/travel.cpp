#include<bits/stdc++.h>
using namespace std;
long long a,b;string s,t;
bool check(){
    long long q,w;
    q=s[0]-48;q*=10;
    q=q+s[1]-48;
    w=t[0]-48;w*=10;
    w=w+t[1]-48;
    if(q==w)return true;
    else return false;
}
bool check2(){
    char e=s[2],r=t[2];int x,y;
    if(e=='D'||e=='F')x=1;
    else x=0;
    if(r=='D'||r=='F')y=1;
    else y=0;
    if(x==y)return true;
    else return false;
}
bool check3(){
    char e=s[2],r=t[2];int x,y;
    if((e=='A'&&r=='C')||(e=='C'&&r=='A'))return false;
    else return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin>>a>>s>>b>>t;
    if(a==b){
        cout<<"1";
        if(check()){
            cout<<"1";
            if(check2()){
                cout<<"1";
                if(check3()){
                    cout<<"1";
                }else{
                    cout<<"0";return 0;
                }
            }else{
                cout<<"00";return 0;
            }
        }else{
            cout<<"000";return 0;
        }
    }else{
        cout<<"0000";return 0;
    }
    return 0;
}