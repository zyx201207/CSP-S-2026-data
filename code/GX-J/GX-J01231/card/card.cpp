#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],sum[300005];
bool b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    stack<int> q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n+1
    ;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[j])
                sum[j]++;
            b[j]=0;
        }
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]])
            {
                while(q.top()!=a[j])
                {
                    b[q.top()]=0;
                    q.pop();
                }
                q.pop();
            }
            q.push(a[j]);
            b[a[j]]=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",sum[i]);
    }
    return 0;
}
