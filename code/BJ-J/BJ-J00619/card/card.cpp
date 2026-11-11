#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005],b[300005]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int c[300005]={0};
        for(int j=i;j<=n;j++)
        {
            if(c[a[j]]>=1)
            {
                int t=j-1;
                while(t>0)
                {
                    if(c[a[t]]>=1) c[a[t]]=0;
                    if(a[t]==a[j])
                    {
                        break;
                    }
                    t--;
                }
            }
            c[a[j]]++;
        }
        for(int j=1;j<=m;j++)
        {
            b[j]+=c[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
