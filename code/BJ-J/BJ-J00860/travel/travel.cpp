#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string X,Y,Z,W;
    cin>>X>>Y>>Z>>W;
    bool f1=(X==Z);
    bool f2=1;
    for(int i=0;i<Y.size()-1;i++)
    {
        if(Y[i]!=W[i]) f2=0; 
    }
    char a=Y[2],b=W[2];
    bool f3,f4;
    if(a=='A'||a=='B'||a=='C')
    {
        f3=(b=='A'||b=='B'|b=='C');
        switch(a)
        {
            case 'A':
                if(b=='B') f4=1;
                else f4=0;
                break;
            case 'B':
                if(b=='A'||b=='C') f4=1;
                else f4=0;
                break;
            default:
                if(b=='B') f4=1;
                else f4=0;
                break;
        }
    }
    else
    {
        f3=(b=='D'||b=='F');
        switch(a)
        {
            case 'D':
                if(b=='F') f4=1;
                else f4=0;
                break;
            default:
                if(b=='D') f4=1;
                else f4=0;
                break;
        }
    }
    cout<<f1<<(f1&f2)<<((f1&f2)&f3)<<(((f1&f2)&f3)&f4);
    return 0;
}