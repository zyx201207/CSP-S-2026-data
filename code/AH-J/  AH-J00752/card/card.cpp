#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000+5],cnt[500000+5],b[1000000+5],f[1000000+5],id[1000000+5];
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
        for(int j=i;j<=n;j++)
        {b[j]=a[j];}
        for(int j=i;j<=n;j++)
        {
            if(f[b[j]]==0)
            {
                f[b[j]]=1;id[b[j]]=j;
            }
            else
            {
                for(int q=id[b[j]];q<j;q++)
                {
                    f[b[q]]=0;b[q]=0;
                }
                id[b[j]]=j;f[b[j]]=1;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(f[b[j]]==1)cnt[b[j]]++;
            f[b[j]]=0;
            //cout<<b[j]<<" ";
        }
        //cout<<endl;
        ab=0;
        for(int j=1;j<=3*100000;j++){
                f[j]=0;b[j]=0;
        id[j]=0;}
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
