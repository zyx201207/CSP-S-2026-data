#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int flag=0;
    cin>>c1>>s1>>c2>>s2;
    int x=0;
    for(int i=0;i<2;i++){
        if(c1[i]==c2[i]) x++;
    }
    if(x==2){ans+="1";flag=1;}
    else {ans+="0000";cout<<ans;return 0;}
    int y=0;
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]) y++;
    }
    if(y==2&&flag==1){flag=2;ans+="1";}
    else ans+="0";
    if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'||flag==1) ans+="00";
    else if((s1[2]+1==s2[2]||s2[2]+1==s1[2])&&((s1[2]!='D'&&s2[2]!='C')||(s1[2]!='C'&&s2[2]!='D'))&&flag==2) ans+="11";
    else if((s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')&&((s1[2]!='D'&&s2[2]!='C')||(s1[2]!='C'&&s2[2]!='D'))) ans+="10";
    cout<<ans;
    return 0;
}
