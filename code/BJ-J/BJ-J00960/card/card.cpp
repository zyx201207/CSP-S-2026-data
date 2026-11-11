#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[100][100],s[1000];
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
        {
            b[i][j]=a[j];
        }
    }
    int h=1;
    for(int i=h;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[h][i]==b[h][j])
            {
                for(int k=j;k<i;k++)
                {
                    b[h][k]=0;
                }
            }
        }
        h++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;i++)
        {
            if(b[i][j]!=0)
            {
                s[b[i][j]]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
