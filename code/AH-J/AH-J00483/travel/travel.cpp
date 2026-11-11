#include<bits/stdc++.h>
using namespace std;
string anss,c,s,cc,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c==cc){
        anss+='1';
        if(s.substr(0,2)==ss.substr(0,2)){
            anss+='1';
            if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')){
                anss+='1';
                if((s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')||(s[2]=='B'||ss[2]=='B')){
                    anss+='1';
                }
                else{
                    anss+='0';
                    cout<<anss;
                    return 0;
                }
            }
            else{
                anss+="00";
                cout<<anss;
                return 0;
            }
        }
        else{
            anss+="000";
            cout<<anss;
            return 0;
        }
    }
    else{
        anss+="0000";
        cout<<anss;
        return 0;
    }
    cout<<anss;
    return 0;

}
