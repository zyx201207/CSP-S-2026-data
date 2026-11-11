#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    flag&=(c1==c2);
    cout<<flag;
    flag&=(s1[0]==s2[0]&&s1[1]==s2[1]);
    cout<<flag;
    flag&=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));
    cout<<flag;
    flag&=(abs(s1[2]-s2[2])==1||min(s1[2],s2[2])+1==max(s1[2],s2[2]));
    cout<<flag;
    return 0;
}
