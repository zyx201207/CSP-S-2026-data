#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    int a,a1,a2;
    char d1;
    int b,b1,b2;
    char d2;
    a1=int(s1[0]-'0');
    a2=int(s1[1]-'0');
    a=a1*10+a2;
    d1=s1[2];
    b1=int(s2[0]-'0');
    b2=int(s2[1]-'0');
    b=b1*10+b2;
    d2=s2[2];
    if(a!=b)
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    if(d1=='A'||d1=='B'||d1=='C')
        if(d2=='D'||d2=='F')
        {
            cout<<"00"<<endl;
            return 0;
        }
    else if(d1=='D'||d1=='F')
        if(d2=='A'||d2=='B'||d2=='C')
        {
            cout<<"00"<<endl;
            return 0;
        }
    cout<<"1";
    if(d1>d2)
    {
        char d3;
        d3=d1;
        d1=d2;
        d2=d3;
    }
    if(d2-d1!=1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<"1";
    cout<<endl;
    return 0;
}
