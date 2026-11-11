#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>node[5005];
int a[5005][5005],w[5005],k[5005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    memset(a,1e9+9,sizeof(a));
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
        cin>>w[i];
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            a[i][x]=y;
            node[x].push_back(i);
        }
    }
    int stt[5001];
    int fin[5001];

       for (int i=1;i<=q;i++)
    {
        int stt,fin;
        cin>>stt>>fin;
        int ans=w[stt]+w[fin];
        queue<int>q;
        q.push(stt);
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            for(int l=0;l<2;l++)
            {
                //1700
            }
        }
        cout<<ans;
    }

    return 0;
}
