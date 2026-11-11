#include<bits/stdc++.h>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
int is;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
        cin>>c1[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>s1[i];
    }
    for(int i=1;i<=2;i++)
    {
        cin>>c2[i];
    }
    for(int i=1;i<=3;i++)
    {
        cin>>s2[i];
    }
    for(int i=1;i<=2;i++)
    {
        if(c1[i]==c2[i]) is++;
    }
    if(is==2) cout<<"1";
    else cout<<"0";
    for(int i=1;i<=2;i++)
    {
        if(s1[i]==s2[i]) is++;
    }
    if(is==4) cout<<"1";
    else cout<<"0";
    if((((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))||((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')))&&is==4) cout<<"1";
    else cout<<"0";
    if(((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B')||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D'))&&is==4) cout<<"1";
    else cout<<"0";
    return 0;
}
