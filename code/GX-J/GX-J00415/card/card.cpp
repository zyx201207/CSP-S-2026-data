#include<bits/stdc++.h>
using namespace std;
int b[300005],c[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans[m];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            c[j]=a[j];
            b[c[j]]++;
            if(b[c[j]]==2)

                for(int k=j-1;k>=i;k--)
                    c[k]=0;
                    b[k]=0;
                b[c[j]]==1;
        for(int z=i;z<=m;z++)
                if(b[z]==1)
                    ans[z]++;


    for(int i=1;i<=n;i++)
        cout<<ans[i];
    return 0;
}
