#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
vector<int> vec;
bool vis[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        vec.clear();
        memset(vis,0,sizeof vis);
        for(int j=i;j<=n;j++)
        {
            if(vis[a[j]])
            {
                while(vec.back()!=a[j])
                {
                    vis[vec.back()]=0;
                    vec.pop_back();
                }
            }
            else
            {
                vec.push_back(a[j]);
                vis[a[j]]=1;
            }
        }
        int len=vec.size();
        for(int j=0;j<len;j++) ans[vec[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
