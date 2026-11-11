#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
bool flag[200005];
stack<int>s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(flag[a[j]])
            {
                while(!s.empty()&&s.top()!=a[j])
                {
                    flag[s.top()]=0;
                    s.pop();
                }
            }
            else
            {
                s.push(a[j]);
                flag[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(flag[j])b[j]++;
        }
        memset(flag,0,sizeof(flag));
        while(!s.empty())s.pop();
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
