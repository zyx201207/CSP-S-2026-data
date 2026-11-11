#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    bool f1 = 1,f2 = 1,f3 = 1,f4 = 1;
    cin>>a1>>a2>>b1>>b2;
    if(a1[0]!=b1[0]||a1[1]!=b1[1])
        f1 = 0;
    cout<<f1;
    if(a2[0]!=b2[0]||a2[1]!=b2[1]||!f1)
        f2 = 0;
    cout<<f2;
    if((a2[2]=='C'&&b2[2]=='D')||(a2[2]=='D'&&b2[2]=='C')||!f1||!f2)
        f3 = 0;
    cout<<f3;
    if(abs(int(a2[2]-b2[2]))!=1||!f1||!f2||!f3)
        f4 = 0;
    cout<<f4;
    return 0;
}
