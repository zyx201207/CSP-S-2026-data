#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    string t1,t2;
    for(int i=0;i<s1.size()-1;i++)
    {
        t1[i]=s1[i],t2[i]=s2[i];
    }
    if(c1==c2&&t1==t2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    int q=s1[2],q1=s2[2];
    if((c1==c2)&&(t1==t2)&&(q1-q==1&&q1!='D')||(q1-q==2&&q1=='C')||(q-q1==1&&q!='D')||(q-q1==2&&q=='C'))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if((c1==c2)&&(t1==t2)&&(q1-q==1&&q1!='D')||(q-q1==1&&q!='D'))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}


