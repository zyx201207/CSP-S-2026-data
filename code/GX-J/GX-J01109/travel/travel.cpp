#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w'",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int f1=1,f2=1,f3=1,f4=1;
    if (c1!=c2){
        cout<<"0000";
        return 0;
    }
    string a1=s1.substr(0,2),a2=s2.substr(0,2);
    if (a1!=a2){
        cout<<"1000";
        return 0;
    }
    char a,b,b1=s1[2],b2=s2[2];
    if (b1>b2){
        a=b1,b=b2;
    }
    else{
        b=b1,a=b2;
    }
    //cout<<a<<' '<<b;
    if (!((a=='C' || a=='B') ||(a=='E' && b=='D'))){
        cout<<"1100";
        return 0;
    }
    if ((a=='C'&&b=='B')||(a=='B'||a=='E')){
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
