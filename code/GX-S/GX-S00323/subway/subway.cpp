#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll C,n,m,d,q;
ll w[500010];
ll k[510],t[510][410],tt[510][510];
vector<int>xa[510];
vector<int>ta[510];
bool a[510][410];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;

    for(int i=1;i<=m;i++)cin>>w[i];
    memset(tt,0X3f3f3f3f,sizeof(tt));
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int z,s;
            cin>>z>>s;
            a[i][z]=1;
            t[i][z]=s;
            xa[i].push_back(z);
            ta[i].push_back(s);
            for(int y:xa[i])
            {
                if(tt[z][y]>t[i][z]+t[i][y])tt[z][y]=t[i][z]+t[i][y];
                if(tt[y][z]>t[i][z]+t[i][y])tt[y][z]=t[i][z]+t[i][y];
            }
        }
    }
    for(int s=1;s<=m;s++)
    {
        tt[s][s]=0;
        for(int z=1;z<=m;z++)
        {
            if(s!=z)
            for(int d=1;d<=m;d++)
            {
                if(s!=d && z!=d)
                {
                    if(tt[s][d]>tt[s][z]+tt[z][d])tt[s][d]=tt[s][z]+tt[d][z];
                    if(tt[d][s]>tt[s][z]+tt[z][d])tt[d][s]=tt[s][z]+tt[d][z];
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+tt[x][y]<<"\n";
    }
    return 0;
}
