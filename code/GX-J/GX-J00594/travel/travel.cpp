#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    int i=0;
    if(c1==c2){
        i=1;
       cout<<i;
    }

    else{
        cout<< i;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<< i;
    }
    else{
        cout <<i;
    }
    if(s1[2]<='C'&&s2[2]<='C')
    {
        cout << i;
    }
    else if(s1[2]>'C'&&s2[2]>'C')
    {
        cout << i;
    }
    else{
        cout << i;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))
        cout<<i;
    else if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))
        cout << i;
    else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
    cout << i;
    else{
        cout<<i;
    }


    return 0;
}
