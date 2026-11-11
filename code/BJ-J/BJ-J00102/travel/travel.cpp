#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a,b,e,f;
string c,d;
char u,v;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>c>>b>>d;
    if(a==b) cout<<"1";
    else 
    {
        cout<<"0000";
        return 0;
    }

    e=(c[0]-'0')*10+(c[1]-'0');
    f=(d[0]-'0')*10+(d[1]-'0');

    if(e==f) cout<<"1";
    else 
    {
        cout<<"000";
        return 0;
    }

    u=c[2];
    v=d[2];
    bool flg1=false;
    if(u=='A')
    {
        if(v=='B' || v=='C') flg1=true;
    }
    else if(u=='B')
    {
        if(v=='A' || v=='C') flg1=true;
    }
    else if(u=='C')
    {
        if(v=='A' || v=='B') flg1=true;
    }
    else if(u=='D')
    {
        if(v=='E') flg1=true;
    }
    else if(u=='E')
    {
        if(v=='D') flg1=true;
    }

    if(!flg1) 
    {
        cout<<"00\n";
        return 0;
    }
    else
    {
        cout<<"1";
        if(u=='A' && v=='B') cout<<"1\n";
        else if(u=='B' && (v=='A' || v=='C')) cout<<"1\n";
        else if(u=='C' && v=='B') cout<<"1\n";
        else if(u=='D' && v=='E') cout<<"1\n";
        else if(u=='E' && v=='D') cout<<"1\n";
        else cout<<"0\n";
    }
    
    return 0;
}