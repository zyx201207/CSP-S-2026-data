#include <bits/stdc++.h>
using namespace std;
bool check(char a,char b)
{
    int cnt = 0;
    char sit1[3] = {'A','B','C'};
    char sit2[2] = {'D','F'};
    for(int i = 0;i < 3;i++)
    {
        if(a == sit1[i] or b == sit1[i])
            cnt++;
    }
    if(cnt == 2) return true;
    cnt = 0;
    for(int i = 0;i < 2;i++)
    {
        if(a == sit2[i] or b == sit2[i])
            cnt++;
    }
    if(cnt == 2) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2)
    {
        if(s1[0] == s2[0] and s1[1] == s2[1])
        {
            if(check(s1[2],s2[2]) == true)
            {
                if(abs(int(s1[2] - s2[2])) == 1 and !(s1[2] == 'C' and s2[2] == 'D' or s1[2] == 'D' and s2[2] == 'C' ))
                {
                    cout<<"1111";
                    return 0;
                }
                else {cout<<"1110"; return 0;}
            }
            else {cout<<"1100"; return 0;}
        }
        else {cout<<"1000"; return 0;}
    }
    else {cout<<"0000"; return 0;}
    return 0;
}
