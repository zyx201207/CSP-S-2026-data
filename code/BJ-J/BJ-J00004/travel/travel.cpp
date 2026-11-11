#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1[0]==s3[0] and s1[1]==s3[1]){
        cout<<1;
        if(s2[0]==s4[0] and s2[1]==s4[1]){
            cout<<1;
            if((s2[2]>='A' and s2[2]<='C' and s4[2]>='A' and s4[2]<='C') or (s2[2]>='D' and s2[2]<='F' and s4[2]>='D' and s4[2]<='F')){
                cout<<1;
                if((s2[2]=='A' and s4[2]=='B') or (s2[2]=='B' and s4[2]=='A') or (s2[2]=='B' and s4[2]=='C') or (s2[2]=='C' and s4[2]=='B') or (s2[2]=='D' and s4[2]=='F') or (s2[2]=='F' and s4[2]=='D')){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
