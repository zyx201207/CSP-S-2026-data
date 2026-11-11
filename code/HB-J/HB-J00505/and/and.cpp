#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> s[30];
int maxn=-1;
int z;
void dfs(int w)
{
    maxn=-1;
    for(int i = w-1;i>=0;i--)s[i].clear();
    for(int i = 0;i<s[w].size();i++)
    {
        int t=s[w][i];
        for(int j = w-1;j>=0;j--)
        {
            if((t&(int)pow(2,j))!=0)
            {
                s[j].push_back(t);
            }
            if(s[j].size()>=m)maxn=max(maxn,j);
        }
    }
    if(maxn==-1)
    {
        cout<<z;
        exit(0);
    }
    z+=pow(2,maxn);
    dfs(maxn);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        int t;
        cin>>t;
        for(int j = 30;j>=0;j--)
        {
            if((t&(int)pow(2,j))!=0)
            {
                s[j].push_back(t);
            }
            if(s[j].size()>=m)maxn=max(maxn,j);
        }
    }
    z=pow(2,maxn);
    dfs(maxn);
    return 0;
}
