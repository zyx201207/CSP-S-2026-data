#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,ans1=0,ans2=0;
    char s1[20],s2[20];
    cin >> c1;
    for(int i = 1;i <=3;i++)
    {
        cin >> s1[i];
    }
    for(int i = 1;i <= 3;i++)
    {
        cin >> s2[i];
    }
    if(c1 == c2)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(s1[1] == s2[1]&&s1[2]==s2[2])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(s1[3] <='C')
    {
        ans1=ans1+1;
    }
    if(s2[3] <='C')
    {
        ans2=ans2+1;
    }
    if(ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if(s1[3] =='D'&&s2[3] =='F'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2]||s1[3] =='F'&&s2[3] =='D'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2]||s1[3] =='A'&&s2[3] =='B'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2]||s1[3]=='B'&&s2[3]=='A'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2]||s1[3]=='B'&&s2[3]=='C'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2]||s1[3]=='C'&&s2[3]=='B'&&ans1 == ans2&&s1[1]==s2[1]&&s1[2]==s2[2])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
