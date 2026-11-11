#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin)
    freopen("travel.out","w",stdout);
    int cx1,cx2;
    string zw1,zw2;
    cin>>cx1>>zw1>>cx2>>zw2;
    int p1=(zw1[0]-48)*10+(zw1[1]-48);
    int p2=(zw2[0]-48)*10+(zw2[1]-48);
    int flag1=(zw1[2]=='A'||zw1[2]=='B'||zw1[2]=='C');
    int flag2=(zw2[2]=='A'||zw2[2]=='B'||zw2[2]=='C');
    map<char,int>m;
    m['A']=1;
    m['B']=2;
    m['C']=3;
    m['D']=4;
    m['F']=5;
    cout<<(cx1==cx2);
    cout<<((cx1==cx2)&&(p1==p2));
    cout<<((cx1==cx2)&&(p1==p2)&&(flag1==flag2));
    cout<<((cx1==cx2)&&(p1==p2)&&(flag1==flag2)&&(abs(m[zw1[2]]-m[zw2[2]]))==1);
    return 0;
}
