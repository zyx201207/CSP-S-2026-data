#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005],b[500005][500005],c[500005][500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cout <<a[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=2*k;j++)
        {
            cin>>b[i][j]>>c[i][j];
        }
    }
    while(q--)
    {
        int be,en,zong=0;
        cin>>be>>en;
        zong+=a[be]+a[en];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*k;j++)
            {
                if(b[i][j]=be)
                {
                    int s=INT_MAX;
                    s=min(s,b[i][j]);
                }

            }
        }
    }
    return 0;
}
