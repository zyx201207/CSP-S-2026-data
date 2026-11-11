#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+2;
int n,m;
int a[N];
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=1;
    while(cnt<=n)
    {
        vector<int> g[n+1];
        int vis[N]={0};
        for(int i=cnt;i<=n;i++)
        {
            g[a[i]].push_back(i);
            vis[a[i]]++;
            //cout<<"hx99"<<" "<<vis[a[i]]<<endl;
            int num=1;
            bool hg=false;
            for(int j=0;j<g[a[i]].size();j++)
            {
                if(g[a[i]][j]!=0&&hg==false)
                {
                    num=g[a[i]][j];
                    g[a[i]][j]=0;
                    hg=true;
                }
                else g[a[i]][j]=0;
            }
            for(int j=num;j<i;j++)
            {
                vis[a[j]]--;
                //cout<<endl<<"qc9999"<<vis[a[j]];
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(vis[i]!=0)
            {
               
                ans[i]++;
            }

        }
        cnt++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
