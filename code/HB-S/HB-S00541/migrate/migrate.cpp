#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;

int c,t,x[N],ans=N,cnt;
void dfs(int num,int cur,int qian,int d)
{
    if (qian==num)
    {
        if (cur<ans)
        {
            ans=cur;
        }
        return;
    }
    for (int i=qian+1;i<=num&&x[i]-x[qian]<=d;i++)
    {
        dfs(num,cur+1,i,d);
    }
}
void dfs2(int num,int cur,int qian,int d)
{
    if (qian==num)
    {
        if (cur==ans)
        {
            cnt++;
        }
        return;
    }
    for (int i=qian+1;i<=num&&x[i]-x[qian]<=d;i++)
    {
        dfs(num,cur+1,i,d);
    }
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>c>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        ans=N;
        for (int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        dfs(n,0,1,d);
        int hai=0;
        for (int i=1;i<=n;i++)
        {
            cnt=0;
            dfs2(i,0,0,d);
            if (cnt==2)
            {
                hai++;
            }
        }
        cout<<hai<<'\n';
    }
    
    return 0;
}