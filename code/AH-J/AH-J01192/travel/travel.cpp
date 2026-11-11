#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int a;
    int b;
    a=(a2[0]-'0')*10+(a2[1]-'0');
    b=(b2[0]-'0')*10+(b2[1]-'0');
    if(a1!=b1)
        cout<<"0000";
    else if(a!=b)
        cout<<"1000";
    else if(min(a2[2],b2[2])<='C'&&max(a2[2],b2[2])>='D')
        cout<<"1100";
    else if(abs(a2[2]-b2[2])>1)
        cout<<"1110";
    else
        cout<<"1111";
    return 0;
}
