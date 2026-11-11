#include <bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    int z1=(s1[0]-'0')*10+(s1[1]-'0'),z2=(s2[0]-'0')*10+(s2[1]-'0');
    if (z1==z2&&c1==c2)
    {
        cout << 1;
    }
    else
        cout << 0;
    char x1=s1[2],x2=s2[2];
    bool b=0;
    if (z1==z2&&c1==c2)
    {
        if (x1=='A'||x1=='B'||x1=='C')
        {
            if (x2=='A'||x2=='B'||x2=='C')
            {
                cout << 1;
                b=1;
            }
            else cout << 0;
        }
        if (x1=='D'||x1=='F')
        {
            if (x2=='D'||x2=='F')
            {
                cout << 1;
                b=1;
            }
            else
                cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    if (b)
    {
        if (x1=='A')
        {
            if (x2=='B')
                cout << 1;
            else
                cout << 0;
        }
        else if (x1=='B')
        {
            if (x2=='A'||x2=='C')
            {
                cout << 1;
            }
            else
                cout << 0;
        }
        else if (x1=='C')
        {
            if (x2=='B')
                cout << 1;
            else
                cout << 0;
        }
        else if (x1=='D')
        {
            if (x2=='F')
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else if (x2=='F')
        {
            if (x2=='D')
                cout << 1;
            else
                cout << 0;
        }
    }
    else
        cout << 0;

    return 0;
}
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.

