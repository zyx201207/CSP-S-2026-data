#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000],b[110000];
int turn[110000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    for(int q=1;q<=n;q++)
    {
        for(int i=1;i<=n;i++)
            b[i]=a[i];
        int c[110000]={};
        for(int i=q;i<=n;i++)
        {
            if(c[b[i]])
            {
                int pos=-1;
                for(int j=q;j<=i;j++)
                {
                    if(b[j]==b[i])
                        pos=j;
                }
                for(int j=pos;j<i;j++)
                {
                    c[b[j]]=0;
                    b[j]=0;
                }
            }
            c[b[i]]=1;
        }
        for(int i=1;i<=m;i++)
        {
            if(c[i])
                turn[i]++;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<turn[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
