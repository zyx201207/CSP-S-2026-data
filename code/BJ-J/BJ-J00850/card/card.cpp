#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005],to[500005],all[300005];
void search(int start)
{
    all[a[start]]++;
    if(start!=n)
    {
        search(to[start+1]);
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
        to[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        num[i]=-1;
    }
    for(int i=n;i>=1;i--)
    {
        if(num[a[i]]==-1)
        {
            num[a[i]]=i;
            search(i);
        }
        else
        {
            to[i]=to[num[a[i]]];
            num[a[i]]=i;
            search(to[i]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<all[i]<<" ";
    }
    return 0;
}
