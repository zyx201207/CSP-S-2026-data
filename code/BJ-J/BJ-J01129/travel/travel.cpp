#include<bits/stdc++.h>
using namespace std;
bool check(char c1,char c2)
{
    bool flag1,flag2;
    if(c1>'C')flag1=1;
    else flag1=0;
    if(c2>'C')flag2=1;
    else flag2=0;
    return flag1==flag2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,h1="",h2="";
    cin>>c1>>s1>>c2>>s2;
    h1=s1[0]+s1[1];
    h2=s2[0]+s2[1];
    if(c1==c2){
        cout<<1;
        if(h1==h2){
            cout<<1;
            if(check(s1[2],s2[2])){
                cout<<1;
                if(s1[2]!='C'&&s2[2]!='C')
                    cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}