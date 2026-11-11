#include<bits/stdc++.h>
using namespace std;
int flag[200010],cur,re[200020],a[200020],ans[200020];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        memset(flag,0,sizeof(flag));
        memset(re,0,sizeof(re));
        cur=0;
        for(int j=i;j<=n;++j)
        {
            if(flag[a[j]]==1)
            {
                int pos;
                for(int k=1;k<=cur;++k)
                {
                    if(re[k]==a[j])
                    {
                        pos=k;
                        break;
                    }
                }
                for(int k=pos;k<=cur;++k)
                {
                    flag[re[k]]=0;
                }
                cur=pos-1;
                flag[a[j]]=1;
                re[++cur]=a[j];
            }
            else{
                    flag[a[j]]=1;
                re[++cur]=a[j];
            }
        }
        for(int j=1;j<=m;++j)
        {
            if(flag[j]==1)
            {
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
