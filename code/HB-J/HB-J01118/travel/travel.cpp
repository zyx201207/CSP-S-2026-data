#include<bits/stdc++.h>
using namespace std;
char c1,c2,s1,s2,s3,c11,c22,s11,s22,s33;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2>>s3>>c11>>c22>>s11>>s22>>s33;
    if(c1==c11&&c2==c22){
        if(s1==s11&&s2==s22){
            if((s3=='A'||s3=='B'||s3=='C')&&(s33=='A'||s33=='B'||s33=='C')){
                if((s3=='A'||s3=='C')&&(s33=='A'||s33=='C'))cout<<"1110";
                else cout<<"1111";
            }else if((s3=='D'||s3=='F')&&(s33=='D'||s33=='F'))cout<<"1111";
            else cout<<"1100";
        }
        else cout<<"1000";
    }else cout<<"0000";
    return 0;
}