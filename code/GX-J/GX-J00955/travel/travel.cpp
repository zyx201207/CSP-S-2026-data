#include <bits/stdc++.h>
using namespace std;

int main()
{   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int x=0,y=0,z=0;
    if(c1==c2){
        cout<<1;
        x=1;
    }
    else cout<<0;

    if(x==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        y=1;
    }
    else cout<<0;

    if(y==1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
        cout<<1;
        z=1;
    }
    else cout<<0;

    if(z==0||(s1[2]<='C'&&s2[2]<='C'&&s1[2]!='B'&&s2[2]!='B')) cout<<0;
    else cout<<1;
    return 0;
}
