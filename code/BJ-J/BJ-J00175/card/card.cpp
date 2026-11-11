#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=500010,M=300010;

int n,m;
int a[N];
int v[N];
vector<int> t;
int h[M];
int vis[M];

signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(v,0,sizeof v);
        memset(vis,0,sizeof vis);
        t.clear();
        for(int j=i;j<=n;j++)
            v[j-i+1]=a[j];
        for(int j=1;j<=(n-i+1);j++)
        {
            if(vis[v[j]])
            {
                //cout<<vis[v[j]]-1<<endl<<endl;
                for(int k=vis[v[j]]-1;k<t.size();k++)
                    t.erase(t.begin()+k);
                t.erase(t.begin()+t.size()-1);
            }
            t.push_back(v[j]);
            vis[v[j]]=t.size();
            //for(int k=1;k<=n;k++)
             //   cout<<vis[k]<<" ";
            //cout<<endl;
            //for(int k=0;k<t.size();k++)
             //   cout<<t[k]<<" ";
            //cout<<endl<<endl;
        }
        for(int j=0;j<t.size();j++)
            h[t[j]]++;
        //for(int j=1;j<=m;j++)
        //    cout<<h[j]<<" ";
        //cout<<endl<<endl;
    }
    for(int i=1;i<=m;i++)
        cout<<h[i]<<" ";
    return 0;
}
