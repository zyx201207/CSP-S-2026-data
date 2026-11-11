#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2;
    string s1,s2;
    cin>>n1>>s1>>n2>>s2;
    if(n1!=n2)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C'))
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    int a=s1[2]-'A',aa=s2[2]-'A';
    if(s1[2]=='D'||s1[2]=='F')
    {
        cout<<1;
        return 0;
    }
    if(abs(a-aa)>1)cout<<0;
    else cout<<1;
    return 0;
}
