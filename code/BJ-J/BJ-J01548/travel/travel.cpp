#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string res="";
    if(c1==c2) res+='1';
    else res+='0';
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&res=="1") res+='1';
    else res+='0';
    bool x=s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D';
    if(x&&res=="11") res+='1';
    else res+='0';
    bool y=s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s2[2]=='D';
    if(y&&res=="111") res+='1';
    else res+='0';
    cout<<res;
    return 0;
}
