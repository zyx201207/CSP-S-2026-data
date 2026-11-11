#include<bits/stdc++.h>
using namespace std;
int n,m,rr,d,p,t[55];
int a[55],b[55][55],c[55][55],x,y;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>rr>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        for(int j=1;j<=t[i];j++)
        {
            cin>>b[i][j]>>c[i][j];
        }
    }
    for(int o=1;o<=p;o++)
    {
        cin>>x>>y;
        int x1,y1,x2,y2,s=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=t[i];j++)
            {
                if(b[i][j]==x)
                {
                    x1=i;
                    x2=j;
                    s+=a[j];
                }
                if(b[i][j]==y)
                {
                    y1=i;
                    y2=j;
                    s+=a[j];
                }
            }
        }
        for(int i=x1;i<=y1;i++)
        {
            s+=c[x1][i];
        }
        cout<<s<<endl;
    }

    return 0;
}
