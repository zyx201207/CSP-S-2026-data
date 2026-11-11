#include <iostream>
#include <string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s1t,s2,s2t,ans="";
    cin >> s1 >> s1t >> s2 >> s2t;
    char a[5]={'A','B','C'},cj1,cj2;
    if(s1==s2){
        ans+="1";
        if(s1t[0]==s2t[0]&&s1t[1]==s2t[1]){
            ans+="1";
            bool bj1=0,bj2=0;
            for(int i=0;i<3;i++){
                if(a[i]==s1t[2]){
                    bj1=1;
                    cj1=s1t[2];
                }if(a[i]==s2t[2]){
                    bj2=1;
                    cj2=s2t[2];
                }
            }if(bj1==bj2){
                ans+="1";
                if(bj1==0)ans+="1";
                else if(bj1==1){
                    if((cj1=='A'&&cj2=='C')&&(cj1=='C'&&cj2=='A'))ans+="0";
                    else ans+="1";
                }
            }else ans+="00";
        }else ans+="000";
    }else ans="0000";
    cout <<ans;
    return 0;
}
