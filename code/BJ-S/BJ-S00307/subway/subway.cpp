#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int M=5e5+10;
int c,n,m,d,q,w[M],k[N],a[N][N],t[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    //cout<<q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    //cout<<q;
    for(int T=1;T<=q;T++)
    {
        int x,y,ans=0,f=0,f1=0,f2=0,a1=0,a2=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==x)
                {
                    f1=i;
                    a1=j;
                }
                if(a[i][j]==y)
                {
                    f2=i;
                    a2=j;
                }
            }
            if(f1==f2)
            {
                f=i;
                break;
            }
            //cout<<k[i];
        }
        ans+=(w[x]+t[f1][a1]+t[f2][a2]+w[y]);
        if(f!=0)
        {

            cout<<ans<<endl;
            continue;
        }
        //cout<<w[x]<<" "<<t[f1][a1]<<" "<<t[f2][a2]<<" "<<w[y]<<" "<<ans<<" ";
        int A,B;
        for(int i=1;i<=k[1];i++)
        {
            for(int j=1;j<=k[2];j++)
            {
                if(a[f1][i]==a[f2][j])
                {
                    A=t[f1][i];
                    B=t[f2][j];
                    ans+=(t[f1][i]+t[f2][j]);
                }
            }
        }
        //cout<<A<<" "<<B<<" ";
        cout<<ans<<endl;
    }
    return 0;
}
