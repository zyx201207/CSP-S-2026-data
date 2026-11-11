#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) {
        cout<<"0000";
        return 0;
    }
    else{
        int x1,x2,c1,c2;
        x1=(s1[0]-48)*10+s1[1]-48;
        x2=(s2[0]-48)*10+s2[1]-48;
        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')  c1=s1[2]-64;
        if(s2[2]=='A'||s2[2]=='B'||s1[2]=='C')  c2=s2[2]-65;
        if(s1[2]=='D')  c1=10;
        if(s1[2]=='F')  c1=11;
        if(s2[2]=='D')  c2=10;
        if(s2[2]=='F')  c2=11;
        cout<<1;
        if(x1!=x2){
            cout<<"000";
            return 0;
        }
        if(abs(c1-c2)>2){
            cout<<"00";
            return 0;
        }
        cout<<1;
        if(abs(c1-c2)==1)   cout<<1;
        else    cout<<0;

    }
    return 0;
}
