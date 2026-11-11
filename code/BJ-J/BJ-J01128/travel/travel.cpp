#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int m=(s1[0]-'0')*10+(s1[1]-'0'),j=(s2[0]-'0')*10+(s2[1]-'0'),l=0,r=0;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    l=1;
    else
    l=0;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    r=1;
    else
    r=0;
    if(c1==c2){
        cout<<1;
        if(m==j){
        cout<<1;
            if(m==j&&l==r)
            {
                cout<<1;
                if(int(s1[2]-s2[2])==1||int(s1[2]-s2[2])==-1)
                cout<<1;
                else cout<<0;
            }
        else cout<<"00";
        }
        else cout<<"000";
    }
    else
    cout<<"0000";
}
