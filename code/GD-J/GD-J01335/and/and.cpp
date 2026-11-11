#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long ans;
multiset <long long> st;
bool f[200005];
bool cmp(long long nx,long long ny)
{
    return nx>ny;
}

void dfs(int step,long long num,int k)
{
    if(step==m)
    {
        ans=max(ans,num);
        return ;
    }
    for(int i=k;i<=n;++i)
    {
        if(a[i]<=ans)
        {
            break;
        }
        if(!f[i])
        {
            f[i]=1;
            dfs(step+1,num&a[i],i);
            f[i]=0;
        }
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        st.insert(a[i]);
        if(st.count(a[i])==m)
        {
            ans=max(ans,a[i]);
        }

    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i)
    {
        //cout<<a[i]<<endl;
        if(a[i]<=ans)
        {
            break;
        }
        f[i]=1;
        dfs(1,a[i],i);
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
