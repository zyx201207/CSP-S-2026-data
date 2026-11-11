#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+5;
int n,m;
ll a[N];
ll ans;

void dfs(int k,ll sum,int cnt)
{
    if(k==n+1||cnt==m)
    {
        //cout<<"到达 此时有"<<cnt<<"个元素\n";
        if(cnt==m)
        {
            //cout<<"发现答案";
            //cout<<"sum="<<sum<<"\n";
            ans=max(ans,sum);
        }
        return ;
    }
    
    for(ll i=0;i<=1;i++)
    {
        //cout<<k<<"选择"<<i<<"\n";
        if(i==0)
        {
            dfs(k+1,sum,cnt);
        }
        else
        {
            dfs(k+1,sum&a[k],++cnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        //1～5
        dfs(1,ll(1<<31)-1,0);
        cout<<ans;
        return 0;
    }
    else if(m==1)
    {
        //6
        ll maxx=-1e9;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    else if(m==n)
    {
        //7
        ll ans=ll(1<<31)-1;
        for(int i=1;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    else if(m==2)
    {
        //8~10
        ll ans=-1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ll k=a[i]&a[j];
                ans=max(ans,k);
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1)
    {
        //11~12


    }
    else
    {
        //13
        sort(a+1,a+n+1);
        ll ans=a[1];
        for(int i=2;i<=m;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }

    return 0;
    /*
    思路：
    对于不同测试点：
    1～5：递归暴力
    6：max(a[i])
    7：sigma(i:1~n) &a[i]
    8～10：枚举二元组
    11～12：枚举不选的
    ------------60pts------------
    13：枚举最高的项
    ------------65pts------------
    */
    fclose(stdin);
    fclose(stdout);
}