#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1] && c2[0]==c1[0]){
        cout<<"1";
        if(s1[1]==s2[1] && s1[0]==s2[0]){
            cout<<"1";
            if(s1[2]<=67 and s1[2]>=65){
                if(s2[2]<=67 and s2[2]>=65){
                    cout<<"1";      
                    if(s1[2]==66 or s2[2]==66){
                        cout<<"1";
                    }
                    else{
                        cout<<"0";
                    }
                }
                if(s2[2]<=70 and s2[2]>=68){
                    cout<<"00";
                }
            }
            if(s1[2]<=70 and s1[2]>=68){
                if(s2[2]<=67 and s2[2]>=65){
                    cout<<"00";
                }
                if(s2[2]<=70 and s2[2]>=68){
                    cout<<"11";
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
