#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int x1,y1,x2,y2,sum=0;
    x1=s1[1]-'0';
    y1=s1[2]-'A'+1;
    x2=s2[1]-'0';
    y2=s2[2]-'A'+1;
    if(s1[0]==1) x1+=10;
    if(s2[0]==1) x2+=10;

    if(c1==c2) cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }

    if(x1==x2) cout<<"1";
    else cout<<"0";

    if(x1==x2 && (s1[2]<='C' && s2[2]<='C' || s1[2]>='D' && s2[2]>='D')) cout<<"1";
    else cout<<"0";

    if(s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D') cout<<"1";
    if((x1+1==x2 || x1-1==x2) ^ (y1+1==y2 || y1-1==y2))
    {
        if(s1[2]=='C' && s2[2]=='D' || s1[2]=='D' && s2[2]=='C')
        {
            cout<<"0";
        }
        else{
            cout<<"1";
        }
    }
    else cout<<"0";
    return 0;
}
