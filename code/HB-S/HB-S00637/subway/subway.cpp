#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        int an=0,ans=1e10,jx[100005],lx[100005],jy[10005],ly[100005],jjx=1,lly=1;
        for(int j=1;j<=n;j++)
        {
            for(int l=1;l<=k[j];l++)
            {
                if(x[i]==a[j][l]) jx[jjx]=j,lx[jjx++]=l;
                if(y[i]==a[j][l]) jy[lly]=j,ly[lly++]=l;
            }
        }
        for(int j=1;j<jjx;j++)
        {
            for(int l=1;l<lly;l++)
            {
                an=w[x[i]]+w[y[i]]+t[jx[j]][ly[l]]+t[jx[j]][ly[l]]+t[jx[j]][ly[l]]+t[jy[l]][ly[l]];
                cout<<endl<<"an"<<an<<endl;
                ans=min(ans,an);
            }
        }
        cout<<"ans"<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
