#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;else{cout<<"0000\n";return 0;}
    int r1=(s1[0]-'0')*10+s1[1]-'0',r2=(s2[0]-'0')*10+s2[1]-'0';
    if(r1==r2)cout<<1;else{cout<<"000\n";return 0;}
    int x=s1[2]-'A',y=s2[2]-'A';
    if((x<3&&y<3)||(x>=3&&y>=3))cout<<1;else{cout<<"00\n";return 0;}
    if(x>=3&&y>=3)cout<<"1\n";
    else{
        if(abs(x-y)==1)cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}