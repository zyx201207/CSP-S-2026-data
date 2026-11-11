#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans=ans+"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    if(s2[2]==s1[2]+1||s1[2]==s2[2]+1){
                        ans="1111";
                    }else{
                        ans="1110";
                    }
                }else{
                    ans="1100";
                }
            }else{
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    ans="1100";
                }else{
                    if(s2[2]==s1[2]+1||s1[2]==s2[2]+1){
                        ans="1111";
                    }else{
                        ans="1110";
                    }
                }
            }
        }else{
            ans="1000";
        }
    }else{
        ans="0000";
    }
    cout<<ans;
    return 0;
}