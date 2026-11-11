#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        ans+='1';
        int aa=int(a2[0]-'0')*10+int(a2[1]-'0');
        int bb=int(b2[0]-'0')*10+int(b2[1]-'0');
        if(aa==bb){
            ans+='1';
            char c1=a2[2],c2=b2[2];
            if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='E')||(c1=='E'&&c2=='D')){
                ans+="11";
            }
            else if(((c1=='D'||c1=='E')&&(c2=='A'||c2=='B'||c2=='C'))||((c2=='D'||c2=='E')&&(c1=='A'||c1=='B'||c1=='C'))){
                ans+="00";
            }
            else ans+="10";
        }
        else ans+="000";
    }
    else ans="0000";
    cout<<ans;

}