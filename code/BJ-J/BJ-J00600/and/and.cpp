#include <bits/stdc++.h>

using namespace std;
#define int long long

struct node
{
    int a;
    vector<int> son;
    int ru;
}t[200010];

int n,m;

int ans=0;

void dfs(int w,int id)
{
    if(w==1)
    {
        ans=max(t[id].a,ans);
        return;
    }
    for(auto a:t[id].son)
    {
        dfs(w-1,a);
    }
    return;
}

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        t[i].ru=0;
        cin>>t[i].a;
        for(int j=0;j<i;j++)
        {
            if((t[i].a&t[j].a)==t[j].a)
            {
                t[i].son.push_back(j);
                //cout<<i<<"->"<<j<<endl;
                t[j].ru++;
            }
            else if((t[i].a&t[j].a)==t[i].a)
            {
                t[j].son.push_back(i);
                //cout<<j<<"->"<<i<<endl;
                t[i].ru++;
            }
        }
    }
    int root;
    for(int i=0;i<n;i++)
    {
        if(!t[i].ru)
        {
            root=i;
        }
    }
    dfs(m,root);
    cout<<ans<<endl;
    return 0;
}
