#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        string x="";
        x+=s1[2];
        x+=s2[2];
        //cout<<x<<endl;
        if(x=="AB"||x=="AC"||x=="BC"||x=="DF"||x=="BA"||x=="CA"||x=="CB"||x=="FD") cout<<1;
        else cout<<0;
    }else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
        string x="";
        x+=s1[2];
        x+=s2[2];
        //cout<<x<<endl;
        if(x=="AB"||x=="BC"||x=="DF"||x=="BA"||x=="CB"||x=="FD") cout<<1;
        else cout<<0;
    }else cout<<0;
    return 0;
}
