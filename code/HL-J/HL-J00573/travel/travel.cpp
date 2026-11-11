#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    char c[4]={'0','0','0','0'};
    if(c1==c2) c[0]='1';
    string row1=s1.substr(0,2),row2=s2.substr(0,2);
    char col1=s1[2],col2=s2[2];
    if(c1==c2&&row1==row2) c[1]='1';
    if(c[1]=='1'&&(col1<='C')==(col2<='C')) c[2]='1';
    if(c[2]=='1'&&abs(col1-col2)==1) c[3]='1';
    else if(c[2]=='1'&&(col1=='D'&&col2=='F')||(col1=='F'&&col2=='D')) c[3]='1';
    cout<<c[0]<<c[1]<<c[2]<<c[3];
    return 0;
}

