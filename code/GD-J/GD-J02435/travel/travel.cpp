#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int ans1,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)ans1=1;
    if(ans1&&s1[0]==s2[0]&&s1[1]==s2[1])ans2=1;
    if(ans2&&s1[2]>='D'&&s2[2]>='D'&&s1[2]<='F'&&s2[2]<='F')ans3=1;
    if(ans2&&s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')ans3=1;
    if(ans3&&abs(s1[2]-s2[2])==1)ans4=1;
    printf("%d%d%d%d",ans1,ans2,ans3,ans4);
    return 0;
}
