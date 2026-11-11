#include<bits/stdc++.h>
using namespace std;\
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+='1';
            if(s1[2]=='A'){
                if(s2[2]=='B'){
                    ans+="11";

                }
                else if(s2[2]=='C'){
                    ans+="10";
                }
                else ans+="00";
            }
            else if(s1[2]=='B'){
                if(s2[2]=='A'){
                    ans+="11";

                }
                else if(s2[2]=='C'){
                    ans+="11";
                }
                else ans+="00";
            }
            else if(s1[2]=='C'){
                if(s2[2]=='B'){
                    ans+="11";

                }
                else if(s2[2]=='A'){
                    ans+="10";
                }
                else ans+="00";
            }
            else if(s1[2]=='D'){
                if(s2[2]=='F'){
                    ans+="11";
                }
                else ans+="00";
            }
            else if(s1[2]=='F'){
                if(s2[2]=='D'){
                    ans+="11";
                }
                else ans+="00";
            }
        }
        else{
            ans+="000";
        }
    }
    else{
        ans="0000";
    }
    cout<<ans;
    return 0;
}
