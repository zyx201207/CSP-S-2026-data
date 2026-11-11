#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    bool ok=true;
    for(int i=0;i<2;i++){
        char a=s2[i],b=s4[i];
        if(a-'0'!=b-'0'){
            ok=false;
            break;
        }
    }
    if(ok)cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    char s33=s2[2],s11=s4[2];
    if(s33-'A'<3&&s11-'A'<3)cout<<1;
    else if(s33-'A'>=3&&s11>=3)cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if(abs((s11-'A')-(s33-'A'))==1)cout<<1;
    else cout<<0;
    return 0;
}
