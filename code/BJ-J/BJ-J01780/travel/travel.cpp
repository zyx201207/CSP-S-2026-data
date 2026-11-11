#include<bits/stdc++.h>
using namespace std;
bool aa(char a,char b){
    if((a=='D'||a=='F')&&(b=='D'||b=='F'))return true;
    if((a=='C'||a=='B')&&(b=='C'||b=='B')||(a=='B'||a=='A')&&(b=='B'||b=='A'))return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool a = (s1[0]==s2[0]&&s1[1]==s2[1]),b = c1==c2;
    cout<<b<<(b&&a)<<(b&&a&&(aa(s1[2],s2[2])||(s1[2]=='A'||s1[2]=='C')&&(s2[2]=='C'||s2[2]=='A')))<<(b&&a&&(aa(s1[2],s2[2])));
    return 0;
}
