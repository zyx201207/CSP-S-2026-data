#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c[3]={0};
    string s[3];
    cin>>c[1];
    for(int i=1;i<=2;i++)
    {
        char b;
        cin>>b;
        s[1]+=b;
    }
    char d[3];
    cin>>d[1];
    cin>>c[2];
    for(int i=1;i<=2;i++)
    {
        char b;
        cin>>b;
        s[2]+=b;
    }
    cin>>d[2];

    if(c[1]==c[2]){cout<<1;}
    else{cout<<0;}

    if(s[1]==s[2]){cout<<1;}
    else{cout<<0;}

    if((d[1]=='A'||d[1]=='B'||d[1]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){cout<<1;}
    else if((d[1]=='D'||d[1]=='F')&&(d[2]=='D'||d[2]=='F')){cout<<1;}
    else{cout<<0;}

    if(d[1]=='A'&&d[2]=='B'||d[1]=='B'&&d[2]=='C'||d[1]=='D'&&d[2]=='F'){cout<<1;}
    else{cout<<0;}
    return 0;
}
