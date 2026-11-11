#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool check1=(c1==c2),check2=false,check3=false,check4=false;
    if(s1[0]==s2[0] && s1[1]==s2[1])
        check2=true;
    if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))
        check3=true;
    if(s1[2]==s2[2]+1 || s1[2]==s2[2]-1)
        check4=true;
    if(check1)
        cout<<1;
    else
        cout<<0;
    if(check1 && check2)
        cout<<1;
    else
        cout<<0;
    if(check1 && check2 && check3)
        cout<<1;
    else
        cout<<0;
    if(check1 && check2 && check3 && check4)
        cout<<1;
    else
        cout<<0;
    return 0;
}
