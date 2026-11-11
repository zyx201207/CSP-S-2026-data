#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m,a[N];
int ans,maxn;
vector<int> v;
void dfs(int cnt,int u)
{
    if (cnt>m)
    {
        int len=v.size();
        if (len!=0) maxn=v[0];
        for (int i=1;i<len;i++)
        {
            maxn&=v[i];
        }
        ans=max(maxn,ans);
        maxn=0;
        return;
    }
    if (u>n)
    {
        return;
    }
    for (int i=u+1;i<=n;i++)
    {
        v.push_back(a[i]);
        dfs(cnt+1,i);
        v.pop_back();
        dfs(cnt,i);
    }
}
vector<int> bit[40];
void get_bits(int num,int pos)
{
    int i=0;
    while (num)
    {
        int tmp=num%2;
        if (tmp==1) bit[i].push_back(pos);
        num/=2;
        i++;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    if (m==1)
    {
        for (int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if (m==n)
    {
        ans=a[1];
        for (int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    if (m==2)
    {
        for (int i=1;i<=n;i++)
            get_bits(a[i],i);
        for (int i=31;i>=0;i--)
        {
            int len=bit[i].size();
            if (len<2)
                continue;
            for (int j=0;j<len;j++)
            {
                for (int k=j+1;k<len;k++)
                {
                    ans=max(ans,a[bit[i][j]]&a[bit[i][k]]);
                }
            }
            break;
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}