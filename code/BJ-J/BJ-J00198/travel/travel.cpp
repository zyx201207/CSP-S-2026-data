#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<'0';
    }
    int t1,t2;
    char n1,n2;
    for(int i=0;i<=s1.size();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            n1[i]=s1[i];
        }
        else
        {
            t1[i]=s1[i];
        }
    }
    for(int i=0;i<=s2.size();i++)
    {
        if(s2[i]>='0'&&s2[i]<='9') n2[i]=s2[i];
        else t2[i]=s2[i];
    }
    if(t1==t2) cout<<'1';
    else cout<<'0';
    if(((t1=='A'||t1=='B'||t1=='C')&&(t2!='D'||t2!='F'))||((t1=='D'||t1=='F')&&(t2=='D'||t2=='F'))) cout<<'1';
    else cout<<'0';
    if((t1=='A'&&t2=='B')||(t1=='B'&&(t2=='A'||t2=='C'))||(t1=='C'&&t2=='B')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')) cout<<'1';
    else cout<<'0';
    return 0;
}
