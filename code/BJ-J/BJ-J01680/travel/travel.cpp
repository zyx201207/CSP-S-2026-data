#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2,t=0;
    char s1[3];
    char s2[3];
    char ans1,ans2,ans3,ans4;
    cin >> c1;
    for(int i = 0;i < 3;i++)
    {
        cin >> s1[i];
    }
    cin >> c2;
    for(int i = 0;i < 3;i++)
    {
        cin >> s2[i];
    }
    if(c1 == c2)
    {
        ans1 = '1';
    }else{
        ans1 = '0';
    }
    if(s1[0] == s2[0] && s1[1] == s2[1])
    {
        ans2 = '1';
    }else{
        ans2 = '0';
    }
    if(ans1 == '1' && ans2 == '1' && (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
    {
        ans3 = '1';
    }else if(ans1 == '1' && ans2 == '1' && (s1[2] == 'F' || s1[2] == 'D') && (s2[2] == 'F' || s2[2] == 'D')){
        ans3 = '1';
        t = 1;
    }else{
        ans3 = '0';
    }
    if(ans1 == '1'&& ans2 == '1' && ans3 == '1')
    {
        if(t = 1)
        {
            ans4 = '1';
        }else if((s1[2] == 'A' || s1[2] == 'B') && (s2[2] == 'A' || s2[2] == 'B'))
        {
            ans4 = '1';
        }else if((s1[2] == 'C' || s1[2] == 'B') && (s2[2] == 'C' || s2[2] == 'B'))
        {
            ans4 = '1';
        }else{
            ans4 = '0';
        }
    }else{
        ans4 = '0';
    }
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
