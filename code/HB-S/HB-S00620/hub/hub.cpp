#include<bits/stdc++.h>
using namespace std;
const int M=1005,N=505,wu=1000000005;
int n,m,c,d,q;
int w[M],a[N][M]={0},t[N][M]={0};
int fufu[M][M]={0};
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        a[i][0]=k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fufu[i][j]=wu;
            if(i==j)fufu[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<a[i][0];j++)
        {
            for(int g=j;g<=a[i][0];g++)
            {
                if(g==j)fufu[a[i][j]][a[i][g]]=0;
                else
                {
                    fufu[a[i][j]][a[i][g]]=min(fufu[a[i][j]][a[i][g]],t[i][j]+t[i][g]);
                    fufu[a[i][g]][a[i][j]]=fufu[a[i][j]][a[i][g]];
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            for(int g=1;g<=m;g++)
            {
                if(g==i||g==j)continue;
                fufu[i][j]=min(fufu[i][j],fufu[i][g]+fufu[g][j]);
                fufu[j][i]=fufu[i][j];
            }
        }
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<fufu[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<w[i]<<" ";
    }*/
    //cout<<endl;
    for(int i=1;i<=q;i++)
    {
        int fufux,fufuy;
        cin>>fufux>>fufuy;
        cout<<(w[fufux]+w[fufuy]+fufu[fufux][fufuy])<<endl;
    }
    return 0;
}
