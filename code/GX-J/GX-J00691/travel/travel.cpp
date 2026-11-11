#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool b1=0,b2=0,b3=0;
    if(c1 == c2){
            cout<<1;
            b1 = 1;
    }
    else cout<<0;
    if(s1[0] == s2[0] && s1[1] == s2[1] && b1){
            cout<<1;
            b2 = 1;
    }
    else cout<<0;
    if(((s1[2] < 'D' && s2[2] < 'D' )||( s1[2] > 'C' && s2[2] > 'C')) && b1 && b2){
            cout<<1;
            b3 = 1;
    }
    else cout<<0;
    int a = s1[2]-s2[2];
    if((a == 1 || a == -1) && b1 && b2 && b3) cout<<1;
    else cout<<0;
    return 0;
}
