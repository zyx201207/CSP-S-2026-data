#include <bits/stdc++.h>
using namespace std;
bool flag[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        flag[1]=1;
    }

    if((s1[0]==s2[0])&&(s1[1]==s2[1])&&flag[1]==1)
    {
        flag[2]=1;
    }

    if((((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))&&flag[2]==1)
    {
        flag[3]=1;
    }

    if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))&&flag[3]==1)
    {
        flag[4]=1;
    }
    for(int i=1;i<=4;i++) cout << flag[i];
    return 0;
}
