#include<bits/stdc++.h>
using namespace std;

const int MAXN=3e5+5;

int m,n,a[MAXN];
int pos[MAXN],ans[MAXN];
bool inq[MAXN];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;j<=n;j++)
    {
        stack<int> q;
        for(int i=j;i<=n;i++)
        {
            if(inq[a[i]])
            {
                while(!q.empty()&&q.top()!=a[i])
                {
                    inq[q.top()]=0;
                    q.pop();
                }
                if(!q.empty())q.pop();
            }
            inq[a[i]]=1;
            q.push(a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            ans[i]+=inq[i];
            inq[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
