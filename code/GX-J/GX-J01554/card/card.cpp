#include<bits/stdc++.h>
using namespace std;
int a[50001],b[30001]={0},sum[30001]={0};
int main(){
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
        for(int j=i;j<=n;j++)
        {
            b[a[j]]++;
            if(b[a[j]]>=2)
            {
              for(int x=1;x<=n;x++)
              {
                  b[x]=0;
              }
              b[a[j]]++;
            }

        }
        for(int c=1;c<=m;c++)
        {
            if(b[c]==1)
            {
                sum[c]=sum[c]+b[c];
                b[c]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
        {
            cout<<sum[i]<<" ";
        }
}
