#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[500005];
bool ispush[500005];
int cnt[500005];
stack<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            ispush[j]=false;
        for(int j=i;j<=n;j++)
        {
            if(ispush[a[j]])
            {
                while(q.top()!=a[j])
                {
                    ispush[q.top()]=false;
                    q.pop();
                }

            }
            else
            {
                q.push(a[j]);

                ispush[a[j]]=true;
            }
        }
        while(!q.empty())
        {
            cnt[q.top()]++;
            q.pop();
        }
    }

    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}
