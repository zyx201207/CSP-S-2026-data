#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
vector<int>f;
int ans[300005];
bool flag[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    for(int k=1;k<=n;k++)
    {
        memset(flag,0,sizeof(flag));
        for(int i=k;i<=n;i++)
        {
            if(flag[a[i]])
            {
                for(int j=f.size()-1;j>=0;j--)
                {
                    if(f[j]==a[i])break;
                    flag[f[j]]=false;
                    f.pop_back();
                }
            }
            else
            {
                f.push_back(a[i]);
                flag[a[i]]=true;
            }
        }
        for(int i=0;i<f.size();i++)ans[f[i]]++;
        while(!f.empty())f.pop_back();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
