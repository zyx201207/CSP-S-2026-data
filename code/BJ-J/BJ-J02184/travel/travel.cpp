#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[8];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])ans[1]=1;
    if(ans[1]==1&&s1[0]==s2[0]&&s1[1]==s2[1])ans[2]=1;
    if(ans[2]==1){
        if(s1[2]<=67&&s2[2]<=67){
            ans[3]=1;
            if(abs(s1[2]-s2[2])==1)ans[4]=1;
        }else if(s1[2]>=68&&s2[2]>=68){
            ans[3]=1;
            ans[4]=1;
        }
    }
    for(int i=1;i<=4;i++)cout<<ans[i];
    return 0;
}