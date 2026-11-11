#include<bits/stdc++.h>
using namespace std;
int n,m,t[300005],t2[300005],t3[300005],f[500005],a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(t2[a[j]]==0)t2[a[j]]++,t3[a[j]]=j;
            else
            {
                for(int k=t3[a[j]]+1;k<j;k++)if(f[k]==0)t2[a[k]]=0,t3[a[k]]=0,f[k]=1;
                t3[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++)if(t2[j]==1)t[j]++;
        memset(t2,0,sizeof(t2));
        memset(t3,0,sizeof(t3));
        memset(f,0,sizeof(f));
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<' ';
    return 0;
}
