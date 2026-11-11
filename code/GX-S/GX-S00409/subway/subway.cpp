#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int n,c,m,d,q,k,a[m][k],t[m][k];
    cin>>c>>n>>m>>d>>q;
    int w[m],x,y,e[q];
    for(int r=1;r<=q;r++)
    {
        e[r]=0;
    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    cin>>x>>y;



        for(int i=0;i<m;i++)
        {
            int z=0;
            z=z+w[x];
            for(int j=0;j<k;j++)
            {
                if(a[i][j]==x)
                {
                    z=z+t[i][j];
                }
                if(a[i][j]==y)
                {
                    z=z+t[i][j];
                }
            }
            z=z+w[y];
            if(e[r]>z)
            {
                e[r]=z;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<e[i]<<endl;
    }
    return 0;
}
