#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[500010],t[300010],v[500010],cnt[300010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int end1=0;
        for(int j=i;j<=n;j++)
        {
            if(t[a[j]]==0||t[a[j]]>end1||v[t[a[j]]]!=a[j])
            {
                v[++end1]=a[j];
                t[a[j]]=end1;
            }
            else
            {
                end1=t[a[j]];
            }
        }
        for(int j=1;j<=end1;j++)
        {
            cnt[v[j]]++;
        }
        memset(t,0,sizeof(t));
        memset(v,0,sizeof(v));
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
