#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
map<char,bool> ce;
map<pair<char,char>,bool> lin;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ce['A']=1;
    ce['B']=1;
    ce['C']=1;
    ce['D']=0;
    ce['E']=0;
    lin[{'A','B'}]=1;
    lin[{'B','C'}]=1;
    lin[{'D','F'}]=1;
    lin[{'B','A'}]=1;
    lin[{'C','B'}]=1;
    lin[{'F','D'}]=1;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            cout<<"1";
            if(ce[s1[2]]==ce[s2[2]])
            {
                cout<<"1";
                pair<char,char> t;
                t.first=s1[2];
                t.second=s2[2];
                if(lin[t])
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
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
