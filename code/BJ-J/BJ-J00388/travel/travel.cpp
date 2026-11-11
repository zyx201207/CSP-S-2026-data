#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ans+='1';
    else ans+='0';
    int a1,a2;
    for(int i=0;i<s1.size();i++){
        if(isdigit(s1[i]))
            a1=a1*10+s1[i]-'0';
        else
            break;
    }
    for(int i=0;i<s2.size();i++){
        if(isdigit(s2[i]))
            a2=a2*10+s2[i]-'0';
        else
            break;
    }
    if(c1==c2&&a1==a2)ans+='1';
    else ans+='0';
    if(c1==c2&&a1==a2&&(s1[s1.size()-1]=='A'||s1[s1.size()-1]=='B'||s1[s1.size()-1]=='C')&&(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C')){
        ans+='1';
        if(s1[s1.size()-1]==s2[s2.size()-1]-1||s1[s1.size()-1]==s2[s2.size()-1]+1)ans+='1';
        else ans+='0';
    }
    else if((c1==c2&&a1==a2&&s1[s1.size()-1]=='D'||s1[s1.size()-1]=='F')&&(s2[s2.size()-1]=='D'||s2[s2.size()-1]=='F')){
        ans+='1';
        if(s1[s1.size()-1]==s2[s2.size()-1]-2||s1[s1.size()-1]==s2[s2.size()-1]+2)ans+='1';
        else ans+='0';
    }
    else ans+="00";
    cout<<ans;
    return 0;
}
