#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;
bool p1,p2,p3,p4;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;

    if (c1==c2) p1=1;

    if (p1==1 && s1[0]==s2[0] && s1[1]==s2[1]) p2=1;

    if (p2==1 && ((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'))) p3=1;

    if (p3==1 && abs(s1[2]-s2[2])==1) p4=1;

    cout<<p1<<p2<<p3<<p4<<endl;

    return 0;
}