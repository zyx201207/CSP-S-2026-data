#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    bool f1=(s1==s3);
    bool f2=(f1&&s2[0]==s4[0]&&s2[1]==s4[1]);
    cout<<f1;
    cout<<f2;
    int a=0,b=0;
    if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))a=0;
    else a=1;
    if((s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))b=0;
    else b=1;
    bool f3=(f2&&(a==b));
    cout<<f3;
    bool f4=(f3&&(a==1||(s2[2]=='B'||s4[2]=='B')));
    cout<<f4;
    return 0;
}
