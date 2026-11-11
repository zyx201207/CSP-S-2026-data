#include<bits/stdc++.h>
using namespace std;
const int M=405;
const int N=205;
vector<int> G[N];
vector<int> H[N];
int tim[M];
int GG[N][N];
#define ll long long
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>tim[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int r=1;r<=k;r++)
        {
            int numm,ttt;
            cin>>numm>>ttt;
            G[numm].push_back(k);
            H[numm].push_back(ttt);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(G[i].size()>1)
            for(int j=1;j<=G[i].size();j++)
                for(int l=1;l<=G[i].size();l++)
                {
                    if(j==l)
                        continue;
                    else
                    {
                        GG[j][l]=H[i][j]+H[i][l];
                        GG[l][j]=GG[j][l];
                    }
                }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                GG[i][j]=0;
            else
                GG[i][j]=2147483647;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                GG[i][j]=min(GG[i][j],GG[i][k]+GG[k][j]);
    while(q--)
    {
        int xx,yy;
        cin>>xx>>yy;
        int ans=2147483647;
        for(int i=1;i<=G[xx].size();i++)
        {
            for(int j=1;j<=G[yy].size();j++)
                ans=min(ans,GG[i][j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

