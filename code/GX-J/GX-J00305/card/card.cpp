#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
bool c[300005];
int n,m;
stack<int>x;
void yx(int i)
{
    while(!x.empty())x.pop();
    memset(c,0,sizeof(c));
    for(int j=i;j<=n;j++)
    {
        if(!c[a[j]])
        {
            x.push(a[j]);
            c[a[j]]=1;
        }
        else
        {
            while(x.top()!=a[j])
            {
                c[x.top()]=0;
                x.pop();
            }
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(c[j]==1)b[j]++;
    }
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)yx(i);
    for(int i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
