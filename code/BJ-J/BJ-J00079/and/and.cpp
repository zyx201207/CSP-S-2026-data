#include<bits/stdc++.h>
using namespace std;
int kkksc;
int n,m;
int a[100010],c[100010];
void dfs(int step,int cnt)
{

    if(cnt<0)
    {
        int res=0;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(c[i]==1)
            {
                if(flag)
                {
                    res=a[i];
                    flag=0;
                }
                else{
                    res&=a[i];
                }
            }
        }
        kkksc=max(kkksc,res);
        return;
    }
    if(step>n)return;
    c[step]=1;
    dfs(step+1,cnt-1);
    c[step]=0;
    dfs(step+1,cnt);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=-1e9;
    for(int i=1;i<=n;++i)
    {

        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1)
    {
        cout<<maxn<<endl;
        return 0;
    }
    else if(m==n)
    {
        int kkk=a[1];
        for(int i=2;i<=n;++i)
        {
            kkk&=a[i];
        }
        cout<<kkk<<endl;
    }
    else if(m==2)
    {
        int ans=0;
        for(int i=1;i<=n;++i)
        {

            for(int j=i+1;j<=n;++j)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
    }
    else{
        dfs(0,m);
        cout<<kkksc<<endl;
    }
    return 0;
}
