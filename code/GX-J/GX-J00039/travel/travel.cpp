#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,sss="0000";
    cin>>c1>>s1>>c2>>s2;
    int a=s1[2]-s2[2];
    if(c1==c2){
       sss[0]='1';
       if(s1[0]==s2[0]&&s1[1]==s2[1]){
        sss[1]='1';
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
            sss[2]='1';
            if((a==-1||a==1)&(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')))){
                sss[3]='1';
                }
            }
        }
    }
    cout<<sss;
    return 0;
}
