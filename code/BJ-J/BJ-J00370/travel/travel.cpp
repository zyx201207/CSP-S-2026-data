#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int che1=-1,che2=-1,line1=-1,line2=-1,seat1=-1,seat2=-1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    che1=(c1[0]-'0')*10+(c1[1]-'0');
    che2=(c2[0]-'0')*10+(c2[1]-'0');
    line1=(s1[0]-'0')*10+(s1[1]-'0');
    line2=(s2[0]-'0')*10+(s2[1]-'0');
    if(s1[2]=='F') seat1=s1[2]-'A';
    else seat1=s1[2]-'A'+1;
    if(s2[2]=='F') seat2=s2[2]-'A';
    else seat2=s2[2]-'A'+1;
    if(che1==che2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(line1==line2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    int p1,p2;
    if(seat1==1 || seat1==2 || seat1==3) p1=1;
    else p1=2;
    if(seat2==1 || seat2==2 || seat2==3) p2=1;
    else p2=2;
    if(p1==p2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(p1==p2 && abs(seat1-seat2)==1) cout<<1;
    else cout<<0;



    return 0;
}
