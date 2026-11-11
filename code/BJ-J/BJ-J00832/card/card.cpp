#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m,a[500005],ans=0;
bool b[200005];
void dfs(int x)
{
    for(int k=x;k<=n;k++)
    {
        s.push(a[k]);
        b[a[k]]=true;
        if(b[a[k]]==true)
        {
            int w=k-1;
            while(w--&&a[k]!=s.top())
            {
                s.pop();
            }
            s.pop();
        }
    }
    return;
}
int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dfs(j);
            if(b[i]==true)
            {
                ans++;
            }
            for(int k=1;k<=m;k++)
            {
                b[k]=false;
            }
            while(s.size()>0)
            {
                s.pop();
            }
            s.pop();
        }
        cout<<ans<<" ";
        ans=0;
    }

    return 0;
}
