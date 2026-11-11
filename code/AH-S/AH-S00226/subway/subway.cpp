#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long c,n,m,d,p,w[500005],t[505][505],a[505][20005],k[505],tu[505][505],l[100005],r[100005],cnt;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            tu[i][j]=1;
            tu[j][i]=1;
            t[j][i]=t[i][j];
        }
    }
    for(int i=1;i<=p;i++)
    {
        cin>>l[i]>>r[i];
        cout<<w[l[i]]+w[r[i]]<<endl;
    }
}
