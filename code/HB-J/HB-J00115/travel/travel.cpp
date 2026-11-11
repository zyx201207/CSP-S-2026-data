#include <bits/stdc++.h>
using namespace std;

bool q1(int c1,int c2,string s1,string s2)
{
    return c1==c2;
}

bool q2(int c1,int c2,string s1,string s2)
{
    if(q1)
    {
        return s1[0]==s2[0] && s1[1]==s1[1];
    }
    else
    {
        return false;
    }
}

bool q3(int c1,int c2,string s1,string s2)
{
    if(q2)
    {
        if(s1[2]=='A')
        {
            if(s2[2]=='B'||s2[2]=='C')
            {
                return true;
            }
        }
        if(s1[2]=='B')
        {
            if(s2[2]=='A'||s2[2]=='C')
            {
                return true;
            }
        }
        if(s1[2]=='C')
        {
            if(s2[2]=='A'||s2[2]=='B')
            {
                return true;
            }
        }
        if(s1[2]=='D')
        {
            if(s2[2]=='F')
            {
                return true;
            }
        }
        if(s1[2]=='F')
        {
            if(s2[2]=='D')
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

bool q4(int c1,int c2,string s1,string s2)
{
    if(q3)
    {
        if(s1[2]=='A')
        {
            if(s2[2]=='B')
            {
                return true;
            }
        }
        if(s1[2]=='B')
        {
            if(s2[2]=='A'||s2[2]=='C')
            {
                return true;
            }
        }
        if(s1[2]=='C')
        {
            if(s2[2]=='B')
            {
                return true;
            }
        }
        if(s1[2]=='D')
        {
            if(s2[2]=='F')
            {
                return true;
            }
        }
        if(s1[2]=='F')
        {
            if(s2[2]=='D')
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }

}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    cout << q1(c1,c2,s1,s2) << q2(c1,c2,s1,s2) << q3(c1,c2,s1,s2) << q4(c1,c2,s1,s2);



    return 0;
}
