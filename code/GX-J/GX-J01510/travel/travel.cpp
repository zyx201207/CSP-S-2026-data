#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s=0;
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
        cout<<"1";
    else
        cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        cout<<"1";
    else
        cout<<"0";
    if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
        cout<<"1";
        s=1;
    }
    else
        cout<<"0";
    int i=s1[2],j=s2[2];
    if(s==1&&i+1==j||s==1&&i-1==j)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}
