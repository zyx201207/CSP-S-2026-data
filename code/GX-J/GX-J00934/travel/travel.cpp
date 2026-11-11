#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=1,k=0,z=0,x1,z1;
    char t,r;
    string a,b,c,d,v={0},s={0};
    cin>>a>>b>>c>>d;
    for(int i=1;i<=b.size();i++)
    {
        v[i]=b[i];
        x++;
    }
    for(int i=1;i<=d.size();i++)
    {
        v[i]=b[i];

    }
    t=b[x];
    r=b[x];
    if(a==c)
    {
        cout<<1;
        if(v==s)
        {
            cout<<1;
            if(t=='A'||t=='B'||t=='C')
            {
                k+=3;
            }
           else if(r=='A'||r=='B'||r=='C')
            {
                z+=3;
            }
            else if(t=='D'||t=='F')
            {
                k+=1;
            }
             else if(r=='D'||r=='F')
            {
                z+=1;
            }
            if(k==z)
            {
                cout<<1;
                if(t='A')x1=1;
                if(t='B')x1=2;
                if(t='C')x1=3;
                if(t='D')x1=4;
                if(t='D')x1=5;
                if(r='A')z1=1;
                if(r='B')z1=2;
                if(r='C')z1=3;
                if(r='D')z1=4;
                if(r='E')z1=5;
                if(x1-z1==1||z1-x1==1)
                {
                    cout<<1;
                }
                else
                    cout<<0;
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }

    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
