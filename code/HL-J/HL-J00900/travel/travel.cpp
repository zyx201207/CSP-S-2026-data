#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)  ans="0000";
    else{
        ans="1000";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans="1100";
            if(int(s1[2]-s2[2])<3||int(s2[2]-s1[2])<3){
                ans="1110";
                if(s1==s1[0]+s1[1]+"F"||s1==s1[0]+s1[1]+"D"){
                    ans="1111";
                    cout<<ans;
                    return 0;
                }
                if(int(s1[2]-s2[2])==1||int(s2[2]-s1[2])==1){
                    ans="1111";
                }
                else{
                    ans="1110";
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
