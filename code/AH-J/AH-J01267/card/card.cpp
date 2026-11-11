#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int t[300005];
queue<int> q,s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++)
        {
            int x=a[j];
            if(t[x])
            {
                while(!q.empty())
                {
                    int y=q.front();
                    q.pop();
                    if(y==x)
                    {
                        break;
                    }
                    s.push(y);
                }
                while(!q.empty())
                {
                    int y=q.front();
                    q.pop();
                    t[y]=0;
                }
                while(!s.empty())
                {
                    int y=s.front();
                    s.pop();
                    q.push(y);
                    t[y]=1;
                }
            }
            t[x]=1;
            q.push(x);
        }
        while(!q.empty())
        {
            int y=q.front();
            ans[y]++;
            q.pop();
            //cout<<y<<" ";
        }
        //cout<<endl;

    }

    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
