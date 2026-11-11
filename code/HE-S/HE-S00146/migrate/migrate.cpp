#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,x=1;
    int n[10001],d[10001];
    int zb[100][100]={0};
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++)
        {
            cin>>zb[i][j];
        }
    }
    for(int i=0;i<t;i++)
    {
        x++;
        cout<<x<<endl;
    }
    return 0;
}
