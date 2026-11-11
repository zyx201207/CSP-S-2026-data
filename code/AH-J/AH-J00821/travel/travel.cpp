#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[6]={0,0,0,1,-1,1};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a[s1[2]-'A']==a[s2[2]-'A']) cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a[s1[2]-'A']==a[s2[2]-'A']){
        if(a[s1[2]-'A']==1) cout<<1;
        else if(s1[2]=='A'&&s2[2]=='B') cout<<1;
        else if(s1[2]=='B'&&s2[2]=='A') cout<<1;
        else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
        else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
