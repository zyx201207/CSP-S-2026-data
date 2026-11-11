#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;

    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else cout<<0;

    if(s1[2]<="D"&&s2[2]<="D")cout<<1;
    else if(s1[2]>="D"&&s2[2]>="D")cout<<1;
    else cout<<0;
    
    char a=1;
    if(s1[2]+a==s2[2]||s1[2]-a==s2[2])cout<<1;
    else cout<<0;








    return 0;
    }
