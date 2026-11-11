#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int r=(c1[0]-'0')*10+(c1[1]-'0');
    int x=(c2[0]-'0')*10+(c2[1]-'0');
    if(r==x)
    {
        cout<<"1";
    }
    else if(r!=x)
    {
        cout<<"0000";
        return 0;
    }
    int t1=(s1[0]-'0')*10+(s1[1]-'0');
    int t2=(s2[0]-'0')*10+(s2[1]-'0');
    if(t1==t2)
    {
        cout<<"1";
    }
    else if(t1!=t2)
    {
        cout<<"000";
        return 0;
    }
    char ch1=s1[2],ch2=s2[2];
    if((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))
    {
        cout<<"1";
    }
    else if((ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F'))
    {
        cout<<"1";
    }
    else
    {
        cout<<"00";
        return 0;
    }
    int a=(ch1-'0')-(ch2-'0');
    if(a<0)
        a=-a;
    if(a==1)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
