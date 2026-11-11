#include<iostream>
#include<cmath>
using namespace std;
bool p;
string s1,c1,s2,c2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    int d1=(s1[0]-'0')*10+(s1[1]-'0');
    int d2=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2&&d1==d2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    int t1,t2;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        t1=1;
    }
    if(s1[2]=='D'||s1[2]=='F'){
        t1=2;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        t2=1;
    }
    if(s2[2]=='D'||s2[2]=='F'){
        t2=2;
    }
    if(c1==c2&&d1==d2&&t1==t2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    int p1,p2;
    if(s1[2]!='F'){
        p1=s1[2]-'A'+1;
    }
    else{
        p1=6;
    }
    if(s2[2]!='F'){
        p2=s2[2]-'A'+1;
    }
    else{
        p2=6;
    }
    if(p1<=3&&p2<=3){
        if(abs(p1-p2)==1){
            p=true;
        }
        else {
            p=false;
        }
    }
    else{
        if(abs(p1-p2)==2){
            p=true;
        }
        else{
            p=false;
        }
    }
    if(c1==c2&&d1==d2&&t1==t2&&p==true)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0; 
}
