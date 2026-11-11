#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,bj,bb;
    cin>>n>>m;
    int a[n+1]={0},b[n+1]={0},tj[m+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int js=1;js<=n;js++)
    {
        for(int i=1;i<=n;i++)
        {
            b[i]=0;
        }
        bb=1;
        for(int i=js;i<=n;i++)
        {
            bj=0;
            for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j])
                {
                    bj=1;
                    for(int ij=j;ij<=n;ij++)
                    {
                        b[ij]=0;
                    }
                    b[j]=a[i];
                    bb=j+1;
                    break;
                }
            }
            if(bj==0)
            {
                b[bb]=a[i];
                bb+=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]>=1 && b[i]<=m)
            {
                tj[b[i]]+=1;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<tj[i]<<" ";
    }
    return 0;
}
