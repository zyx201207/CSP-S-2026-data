#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t[100005];
bool vis[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int r = 1;r<=n;r++)
    {
        memset(vis,false,sizeof(vis));
        stack<int> q;
        for(int i = r;i<=n;i++)
        {
            if(!vis[a[i]])
            {
                q.push(a[i]);
                //cout<<a[i]<<endl;
                vis[a[i]]=true;
            }
            else
            {
                //cout<<a[i]<<" ||";
                while(!q.empty() && q.top()!=a[i])
                {
                    //cout<<q.top()<<" ";
                    vis[q.top()]=false;
                    q.pop();
                }
                cout<<endl;
            }
            //if(!q.empty()) cout<<q.top();
        }
        while(!q.empty())
        {
            //cout<<q.top();
            t[q.top()]++;
            q.pop();
        }
        //cout<<endl;
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<t[i]<<" ";
    }  

    return 0;
}