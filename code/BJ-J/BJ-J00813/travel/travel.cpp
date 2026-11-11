#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1=false,f2=false,f3=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s2){
        cout<<1;
        f1=true;
    }
    else cout<<0;
    if(f1&&s2[0]==s4[0]&&s2[1]==s4[1]){
        cout<<1;
        s2=true;
    }
    else cout<<0;
    if(f1&&f2&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'))){
        cout<<1;
        f3=true;
    }
    else cout<<0;
    if(f3&&!((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A'))) cout<<1;
    else cout<<0;
    return 0;
}
