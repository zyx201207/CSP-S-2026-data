#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[505][505];
int c,n,m,d,q;
int v[500005];
vector<int> be[500005],w[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k,x,ww;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>ww;
            be[x].push_back(i);
            w[x].push_back(ww);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int x=1;x<=m;x++)
    {
        for(int j=0;j<(be[x].size())-1;j++)
        {
            for(int k=j+1;k<(be[x].size());k++)
            {
                f[be[x][j]][be[x][k]]=min(f[be[x][j]][be[x][k]],w[x][j]+w[x][k]);
               
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0;
    }
    for(int len=3;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=l;k<r;k++)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+f[k][k+1]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,t;
        cin>>s>>t;
        int ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<be[s].size();j++)
        {
            for(int k=0;k<be[t].size();k++)
            {
				int res=be[s][j],cnt=be[t][k];
				if(res>cnt)swap(res,cnt);
                ans=min(ans,f[res][cnt]+w[s][j]+w[t][k]);
            }
        }
        cout<<(ans+v[s]+v[t])<<'\n';
    }
    return 0;
}
