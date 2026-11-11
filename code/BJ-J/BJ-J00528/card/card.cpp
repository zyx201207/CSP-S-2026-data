#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];

void olivia(int r)//di ji lun
{
    int c[500005],cnt=0;
    bool nu[300005]={};
    //int nu[300005];
    //nu[a[r-1]]=r-1;
    //for(int i=r;i<n;i++)
    //{
    //    if(nu[a[i]]==0&&a[i]!=a[r-1]) nu[a[i]]=i;
    //}
    for(int i=r-1;i<n;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(c[j]==a[i])
            {
                for(int k=j;k<cnt;k++)
                {
                    c[k]=0;
                }
                cnt=j;
            }
        }
        c[cnt]=a[i];
        cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        nu[c[i]]=true;
    }
    for(int i=1;i<=m;i++)
    {
        ans[i]+=(int)nu[i];
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        olivia(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
}
