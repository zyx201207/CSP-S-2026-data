#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    string n[4],m[4],tmp[5];
    for(int i=1;i<=4;i++)
        cin>>tmp[i];
    n[2]="",m[2]="";
    n[1]=tmp[1],n[2]+=(char)tmp[2][0],n[3]=tmp[2][2];
    m[1]=tmp[3],m[2]+=(char)tmp[4][0],m[3]=tmp[4][2];
    n[2]+=(char)tmp[2][1],m[2]+=(char)tmp[4][1];
    if(n[1]==m[1])
        cout<<'1';
    else
        cout<<'0';
    bool a=(n[1]==m[1]);
    if(n[2]==m[2]&&a)
        cout<<'1';
    else
        cout<<'0';
    bool b=(n[2]==m[2]&&a);
    if(((n[3][0]<='C'&&m[3][0]<='C')||(n[3][0]>='D'&&m[3][0]>='D'))&&(a&&b))
        cout<<'1';
    else
        cout<<'0';
    if(abs(n[3][0]-m[3][0])==1)
        if((!(n[3][0]=='C'&&m[3][0]=='D')||(n[3][0]=='D'&&m[3][0]=='C'))&&(a&&b))
            cout<<'1';
        else
            cout<<'0';
    else
        cout<<'0';
    return 0;
}
