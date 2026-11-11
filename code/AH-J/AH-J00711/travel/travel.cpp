#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    string ans;
    bool f=false,f1=true;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans+="1";
        f=true;
    }
    else
    {
        ans+="0";
    }
    if(f==false){
        ans+="00";
        cout<<ans;
        return 0;
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
    {
        ans+="1";
    }
    else{
        ans+="0";
    }
    if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
       ans+="1";
    }
    else if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
        ans+="0";
    }
    else
    {
        if(s1[2]>s2[2]){
            int a=s1[2]-s2[2];
            if(a==1){
                ans+="1";
            }
            else{
                ans+="0";
            }
        }
        else
        {
            int b=s2[2]-s1[2];
            if(b==1){
                ans+="1";
            }
            else{
                ans+="0";
            }
        }
    }
    cout<<ans;
    return 0;

}
