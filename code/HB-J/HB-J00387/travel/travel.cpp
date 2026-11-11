#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,z1,z2;
    cin>>x1>>z1>>x2>>z2;
    if(x1!=x2){cout<<"0000";return 0;}
    cout<<"1";
    if(z1[0]!=z2[0]||z1[1]!=z2[1]){cout<<"000";return 0;}
    cout<<"1";
    if(z1[2]=='A'&&z2[2]=='C'||z1[2]=='C'&&z2[2]=='A'){cout<<"10";return 0;}
    if(!(z1[2]=='D'&&z2[2]=='C'||z1[2]=='C'&&z2[2]=='D')&&abs(z1[2]-z2[2])==1||z1[2]=='D'&&z2[2]=='F'){cout<<"11";return 0;}
    else {cout<<"00";return 0;}
    return 0;
}
