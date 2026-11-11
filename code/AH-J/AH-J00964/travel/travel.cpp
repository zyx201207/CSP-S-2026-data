#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    string r="";
    if(a1==b1){
        r=r+"1";
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            r=r+"1";
            if(a2[2]=='D'&&b2[2]=='F'||a2[2]=='F'&&b2[2]=='D'){
                r=r+"11";
            }else if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
                r=r+"1";
                if(a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C')||a2[2]=='C'&&b2[2]=='B'){
                    r=r+"1";
                }else{
                    r=r+"0";
                }
            }else{
                r=r+"00";
            }
        }else{
            r=r+"000";
        }
    }else{
        r=r+"0000";
    }
    cout<<r;
    return 0;
}
