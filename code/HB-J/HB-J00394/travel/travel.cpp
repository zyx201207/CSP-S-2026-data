#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
    }else{
        ans+="0000";
        cout<<ans;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans+="1";
    }else{
        ans+="000";
        cout<<ans;
        return 0;
    }
    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
        ans+="1";
    }else{
        ans+="00";
        cout<<ans;
        return 0;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
        ans+="1";
        cout<<ans;
        return 0;
    }else{
        ans+="0";
        cout<<ans;
        return 0;
    }
    return 0;
}
