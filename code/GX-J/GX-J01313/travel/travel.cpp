#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2 ? 1:0);
    cout<<(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] ? 1:0);
    int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
    cout<<(c1==c2 && ((a<4 && b<4) || (a>3 && b>3) ) && s1[0]==s2[0] && s1[1]==s2[1] ? 1:0);
    cout<<(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && (abs(a-b)==1 || (a==4 && b==6)) && ((a<4 && b<4) || (a>3 &&b>3) ) ? 1:0);
    return 0;
}
