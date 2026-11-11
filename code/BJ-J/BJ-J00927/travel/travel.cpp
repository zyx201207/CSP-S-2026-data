#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int x[16];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    for(int i=1;i<=3;i++) x[i]=1;
    for(int i=4;i<=6;i++) x[i]=2;
    if(s1==s3){
        cout<<'1';
        if(s2[0]==s4[0]&&s2[1]==s4[1]){
            cout<<'1';
            if(x[s2[2]-64]==x[s4[2]-64]){
                cout<<'1';
                if(s2[2]=='A'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='A') cout<<"0";
                else cout<<'1';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
