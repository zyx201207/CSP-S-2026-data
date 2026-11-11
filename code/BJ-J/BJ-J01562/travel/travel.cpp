#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int ans[10]={0,0,0,0};
signed main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]) ans[0]=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans[1]=1;
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) ans[2]=1;
        if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')) ans[2]=1;
    }
    if(s1[2]=='A'&&s2[2]=='B') ans[3]=1;
    if(s1[2]=='B'&&s2[2]=='C') ans[3]=1;
    if(s1[2]=='C'&&s2[2]=='D') ans[3]=1;
    if(s1[2]=='D'&&s2[2]=='E') ans[3]=1;
    if(s1[2]=='B'&&s2[2]=='A') ans[3]=1;
    if(s1[2]=='C'&&s2[2]=='B') ans[3]=1;
    if(s1[2]=='D'&&s2[2]=='C') ans[3]=1;
    if(s1[2]=='E'&&s2[2]=='D') ans[3]=1;
    for(int i=0;i<=3;i++) cout<<ans[i]<<" ";
    return 0;
}
