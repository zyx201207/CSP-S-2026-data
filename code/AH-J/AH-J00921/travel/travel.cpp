#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int f=0;
    if(c1==c2){
        f++;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            f++;
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
                f++;
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
                    f++;
                }
            }else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                f++;f++;
            }
        }
    }
    if(f==0)cout<<"0000";
    if(f==1)cout<<"1000";
    if(f==2)cout<<"1100";
    if(f==3)cout<<"1110";
    if(f==4)cout<<"1111";
    return 0;
}
