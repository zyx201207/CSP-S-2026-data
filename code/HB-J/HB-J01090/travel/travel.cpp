#include <bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
bool f1,f2,f3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<'1';
        f1=1;
    }
    else cout<<'0';
    if(f1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<'1';
        f2=1;
    }
    else cout<<'0';
    if(f2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
        cout<<'1';
        f3=1;
    }
    else cout<<'0';
    if(f3&&((s1[2]<='C'&&abs(s1[2]-s2[2])==1)||(s1[2]>'C'&&abs(s1[2]-s2[2])==2)))   cout<<'1';
    else cout<<'0';
    return 0;
}
