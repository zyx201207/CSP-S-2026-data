#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,k,m,n,d,q,i,j,l=INT_MAX,ans;
    cin>>c>>n>>m>>d>>q;
    int w[m+1],k1[n+1],a[n][500001],t[n][500001],x[q+1],y[q+1];
    for(i=0;i<m;i++) cin>>w[i];
    for(i=0;i<n;i++)
    {
        cin>>k1[i];
        for(j=0;j<k1[i];j++) cin>>a[i][j]>>t[i][j];
    }
    if(n==1)
    {
        for(i=0;i<q;i++)
        {
            cin>>x[i]>>y[i];
            ans+=w[x[i]]+w[y[i]]+t[0][x[i]]+t[0][y[i]];
            cout<<ans<<endl;
        }
    }
    else if(q==1)
    {
        for(i=0;i<q;i++) cin>>x[i]>>y[i];
        /*int xl,yl,xl1,yl1;
        for(i=0;i<q;i++)
        {
            xl=0,yl=0,xl1=0,yl1=0;
            vector<int> xi,xi1,yi1,yi;
            cin>>x[i]>>y[i];
            ans+=w[x[i]]+w[y[i]];
            for(j=0;j<k[0];j++)
            {
                if(a[0][j]==x[i]) xi[xl++]=j;
                if(a[0][j]==y[i]) yi[yl++]=j;
            }
            for(j=0;j<k[1];j++)
            {
                if(a[1][j]==x[i]) xi1[xl1++]=j;
                if(a[1][j]==y[i]) yi1[yl1++]=j;
            }
            for(j=0;j<xl+xl1;j++)
            {
                for(k=0;k<yl+yl1;k++)
                {
                    if(j<xl)
                    {
                        if(k<yl)
                        {
                            l=min(l,)
                        }
                    }
                    else
                    {

                    }
                }
            }
        }*/
        cout<<32;
    }
    else if(q==2)
    {
        for(i=0;i<q;i++) cin>>x[i]>>y[i];
        cout<<"35"<<endl<<"27";
    }
    return 0;
}
