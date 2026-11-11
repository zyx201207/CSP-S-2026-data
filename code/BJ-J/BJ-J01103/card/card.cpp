#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[5005]={};
    int vis[5005][5005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(vis[i][a[j]]==0)
            {
                s.push(a[j]);
                vis[i][a[j]]=1;
            }
            else
            {
                s.pop();
                while(s.top()!=a[j])
                {
                    vis[i][s.top()]=0;
                    s.pop();
                }
            }
        }
        while(s.empty()) s.pop();
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(vis[j][k]!=0)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<" ";
        cnt=0;
    }
    return 0;
}
