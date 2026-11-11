#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) t[1] = 1;
    else t[1] = 0;
    if(t[1]&&s1[0]==s2[0]&&s1[1]==s2[1]) t[2] = 1;
    else t[2] = 0;
    if(t[2]==1)
    {
        if((s1[2]=='A'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='B')||(s2[2]=='C'||s2[2]=='D'||s2[2]=='E'&&s1[2]=='C'||s1[2]=='D'||s1[2]=='E'))
        {
            t[3] = 1;
            if(s1[2]=='A'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='B') t[4] = 1;
            if(s1[2]=='C'||s1[2]=='D'&&s2[2]=='C'||s2[2]=='D') t[4] = 1;
            if(s1[2]=='D'||s1[2]=='E'&&s2[2]=='D'||s2[2]=='E') t[4] = 1;
        }

    }
    for(int i = 1;i <= 4;i++)
    {

        cout << t[i];
    }

    return 0;
}