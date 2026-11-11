#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int if1=int(c1==c2),if2=int(if1&&s1[0]==s2[0]&&s1[1]==s2[1]),if3=int(if2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))),if4=int(if1&&if2&&if3&&(abs(s1[2]-s2[2])==1));
    cout<<if1<<if2<<if3<<if4;
    return 0;
}
