#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[15];
int a[15][15];
int t[15][15];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    
    if(n==1)
    {
        for(int i=1;i<=m;i++)
            cin>>w[i];
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[1][j]>>t[1][j];
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+a[1][x]+a[1][y]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}