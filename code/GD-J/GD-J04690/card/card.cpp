#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+100],b[n+100],c[100000];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    b[0]=a[0];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[j]=a[j];
            if(b[j]==b[i])
            {
                for(int k=j;k>i;k--)
                {
                    b[k]=0;
                }
            }
        }
    }
    for(int i = 0;i<m;i++)
    {
        if(b[i]==1)
        {
            c[0]++;
        }
        if(b[i]==2)
        {
            c[1]++;
        }
        if(b[i]==3)
        {
            c[2]++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout << c[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
