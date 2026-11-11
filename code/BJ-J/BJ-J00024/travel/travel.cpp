#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    cout<<(s1==s3);
    cout<<((s1==s3)&&(s2.substr(0,2)==s4.substr(0,2)));
    cout<<((s1==s3)&&(s2.substr(0,2)==s4.substr(0,2))&&((s2[2]<='C')+(s4[2]<='C')!=1));
    cout<<((s1==s3)&&(s2.substr(0,2)==s4.substr(0,2))&&((s2[2]<='C')+(s4[2]<='C')!=1)&&((abs(s2[2]-s4[2])==1)||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')));
}
