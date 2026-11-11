#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
bool vis[5][5];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else return cout<<"0000",0;
    bool f=1;
    for(int i=0; i<s1.size()-1; i++)
    {
        if(s1[i]!=s2[i]) f=0;
    }
    cout<<f;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            vis[i][j]=1;

        }
    }
    for(int i=3; i<5; i++)
    {
        for(int j=3; j<5; j++)
        {
            vis[i][j]=1;

        }
    }
    if(vis[s1[2]-'A'][s2[2]-'A']&&f){
        cout<<1;
        if(s1[2]+1==s2[2]) cout<<1;
        else cout<<0;
    }
    else cout<<"00";

    return 0;
}
