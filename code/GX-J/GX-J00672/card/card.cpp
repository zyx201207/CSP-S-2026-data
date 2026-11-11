#include<bits/stdc++.h>
using namespace std;
int a[10086];
int m1[10086];
main()
{
    //no shifang my zhishi nononononono!!!!!!!!!!!!!!!
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p[m];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=0;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            a[j]=m1[j];
            for(int x=i;x<=n;x++)
            {
                if(a[j]==m1[x])
                {
                    for(int r=x;r<=n;r++)
                    {
                        m1[r]=0;
                    }
                }
            }
        }
        for(int o=i;o<=n;o++)
        {
            if(m1[o]!=0)
            {
                p[o]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<p[i];
    }
    return 0;
}
