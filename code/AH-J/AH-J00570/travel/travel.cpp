#include<bits/stdc++.h>
using namespace std;
string s;
string c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1;
    cin>>c2>>s2;
    if(c1==c2){
        s+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            s+="1";
            if(s1[2]<='C'&&s2[2]<='C'){
                s+="1";
                if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
                    s+="0";
                }else{
                    s+="1";
                }
            }else{
                s+="00";
            }
        }else{
            s+="000";
        }
    }else{
        s+="0000";
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
