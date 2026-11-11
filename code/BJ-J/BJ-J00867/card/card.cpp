#include<iostream>
using namespace std;
int a[500000],ans[300000],b[500000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            b[j]=a[j];
        }
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<j;k++)
            {
                if(a[j]==a[k])
                {
                    for(int l=k;l<j;l++)
                    {
                        b[l]=-1;
                    }
                }
            }
        }
        for(int j=i;j<n;j++)
        {
            if(b[j]!=-1) ans[b[j]-1]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}