#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    bool flat=true;
    cin >>c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        cout << 1;
    }
    else{
        cout << 0 << 0<<0<<0;
        return 0;
    }
    for(int i=0; i <= 1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flat=false;
        }
    }
    if(flat)
    {
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    char a=s1[2];
    char b=s2[2];
    if(a=='F'&&b=='D')
    {
        cout<<11;
        return 0;
    }
    if(a=='D'&&b=='F')
    {
        cout << 11;
        return 0;
    }
    
    if(a=='A'&&(b=='B'||b=='C'))
    {
        cout << 1;
    }
    else if(a=='B'&&(b=='A'||b=='C'))
    {
        cout << 1;
    }
    else if(a=='C'&&(b=='A'||b=='B'))
    {
        cout << 1;
    }
    else{
        cout << 0 << 0;
        return 0;
    }
    if(a==b+1||b==a+1)
    {
        cout <<1;
    }
    else{
        cout << 0;
    }

    return 0;
}
