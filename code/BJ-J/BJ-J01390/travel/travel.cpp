#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int num1,num2;
    string pos1,pos2;
    cin>>num1>>pos1>>num2>>pos2;
    if(num1==num2)cout<<1;
    else cout<<0;

    if(pos1[0]==pos2[0]&&pos1[1]==pos2[1])cout<<1;
    else cout<<0;

    if((pos1[2]<='C'&&pos2[2]<='C')||(pos1[2]>'C'&&pos2[2]>'C'))cout<<1;
    else cout<<0;

    if(pos1[2]<='C'&&pos2[2]<='C'&&abs(pos1[2]-pos2[2])==1||pos1[2]=='D'&&pos2[2]=='F')cout<<1;
    else cout<<0;
    return 0;
}
