#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<1;
        a=1;
    }
    else{
        cout<<0;
    }
    if(a2[0]==b2[0] && a2[1]==b2[1] && a==1)
    {

        cout<<1;
        b=1;
    }
    else{
        cout<<0;
    }
    if(a2[2]>='D' && b2[2]<='F' || b2[2]<='C' && b2[2]<='A' && a==1 && b==1){
        cout<<1;
        c=1;
    }
    else{
        cout<<0;
    }
    if(a==1 && b==1 && c==1 && a2[2]==b2[2]+1 || a2[2]==b2[2]-1 && a==1 && b==1 && c==1)
    {

        cout<<1;
    }
    else{
        cout<<0;
    }

    return 0;
}
