#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],lst[300001],pre[500005],nxt[500005],ans[300001];
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
        memset(lst,0,sizeof(lst));
        lst[a[i]]=i;
        pre[i]=0;
        nxt[0]=i;
        nxt[n]=-1;
        for(int j=i+1;j<=n;j++)
        {
            pre[j]=j-1;
            nxt[j-1]=j;
            if(lst[a[j]]!=0)
            {
                nxt[pre[lst[a[j]]]]=j;
                pre[j]=pre[lst[a[j]]];
                for(int k=lst[a[j]];k<j;k++)
                {
                    lst[a[k]]=0;
                }
            }
            lst[a[j]]=j;
        }
        int j=0;
        while(j!=-1)
        {
            ans[a[j]]++;
            j=nxt[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
