#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    string b;
    string c;
    string d;
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    int x[5]={0};
    int i=1;
    if(a==c)
    {
        x[i]=1;
        i++;
    }
    if(b[0]==d[0]&&b[1]==d[1])
    {
        x[i]=1;
        i++;
    }
    if(b[2]=='A'&&d[2]=='C')
    {
        x[i]=1;
    }
    if(b[2]=='C'&&d[2]=='A')
    {
        x[i]=1;
    }
    if(b[2]=='D'&&d[2]=='F')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='F'&&d[2]=='D')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='A'&&d[2]=='B')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='B'&&d[2]=='A')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='B'&&d[2]=='C')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='C'&&d[2]=='B')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='D'&&d[2]=='F')
    {
        x[i]=1;
        x[i+1]=1;
    }
    if(b[2]=='F'&&d[2]=='D')
    {
        x[i]=1;
        x[i+1]=1;
    }
    for(int i=1;i<=4;i++)
    {
        cout<<x[i];
    }
    return 0;
}

