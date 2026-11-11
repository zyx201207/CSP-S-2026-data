#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t[105][105],c1,c2;
char s1[105],s2[105];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }
    if(s1[0]*10+s1[1]==s2[0]*10+s2[1])cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))cout<<11;
    else if((s1[2]-'A'<=2&&s2[2]-'A'<=2)){
        if(abs(s1[2]-s2[2])==1)cout<<11;
        else cout<<10;
    }
    else cout<<"00";
    return 0;
}
