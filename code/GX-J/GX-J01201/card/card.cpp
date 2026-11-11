#include <bits/stdc++.h>

using namespace std;
int a[500001];
int s[500001];
int main()
{
    freopen("cardin","r",stdin);
    freopen("cardout","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans[m+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<long long>q;
    for(int i=1;i<=n;i++)
    {
        int s[500001]={0};
        for(int j=i;j<=n;j++)
        {
            while(!q.empty()&&s[a[j]]==1)
            {
                s[q.top()]=0;
                q.pop();
            }
            q.push(a[j]);
            s[a[j]]=1;
        }
        while(!q.empty())
        {
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
