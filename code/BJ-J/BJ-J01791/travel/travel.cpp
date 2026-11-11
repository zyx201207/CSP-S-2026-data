#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        ans1=1;
        if(s2[0]==c2[0]&&s2[1]==c2[1]){
            ans2=1;
            char s=s2[2],c=c2[2];
            if(s=='A'){
                //cout<<1;
                if(c=='B'){
                    ans3=ans4=1;
                }else if(c=='C'){
                    ans3=1;
                }
            }else if(s=='B'){
                //cout<<2;
                if(c=='A'||s=='C')ans3=ans4=1;
            }else if(s=='C'){
                //cout<<3;
                if(c=='B'){
                    ans3=ans4=1;
                }else if(c=='A'){
                    ans3=1;
                }
            }else if(s=='D'){
                //cout<<4;
                if(c=='F')ans3=ans4=1;
            }else if(s=='F'){
                //cout<<5;
                if(c=='D')ans3=ans4=1;
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
