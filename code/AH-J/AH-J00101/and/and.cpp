#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],ans,p[200005],b[200005],cnt[5];
bool used[25];
bool f(){
    for (int i=1;i<=n;i++)
    {
        if (a[i]>=4)
        {
            return false;
        }
    }
    return true;
}
void dfs(int x,int num){
    if (x==n+1)
    {
        if (num!=m)
        {
            return;
        }
        ll res=-1;
        for (int i=1;i<=n;i++)
        {
            if (used[i])
            {
                if (res==-1)
                {
                    res=a[i];
                }
                res&=a[i];
            }
        }
        ans=max(ans,res);
        return;
    }
    used[x]=true;
    dfs(x+1,num+1);
    used[x]=false;
    dfs(x+1,num);
}
void solve1(){
    dfs(1,0);
    cout<<ans<<"\n";
}
void solve2(){
    cout<<a[n]<<"\n";
}
void solve3(){
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)
            {
                continue;
            }
            ans=max(ans,a[i]&a[j]);
        }
    }
    cout<<ans<<"\n";
}
void solve4(){
    ans=a[1];
    for (int i=1;i<=n;i++)
    {
        ans&=a[i];
    }
    cout<<ans<<"\n";
}
void solve5(){
    p[0]=a[1],b[n+1]=a[n];
    for (int i=1;i<=n;i++)
    {
        p[i]=p[i-1]&a[i];
    }
    for (int i=n;i>=1;i--)
    {
        b[i]=b[i+1]&a[i];
    }
    for (int i=1;i<=n;i++)
    {
        ll res;
        if (i==1)
        {
            res=b[2];
        }
        else if (i==n)
        {
            res=p[n-1];
        }
        else
        {
            res=p[i-1]&b[i+1];
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
}
void solve6(){
    ll num=0;
    for (int i=1;i<=n;i++)
    {
        if (!a[i])
        {
            num++;
        }
        cnt[0]++;
        for (int j=1;j<=a[i];j++)
        {
            if (j&a[i])
            {
                cnt[j]++;
            }
        }
    }
    if (n-num<m)
    {
        cout<<0<<"\n";
        return;
    }
    for (int j=3;j>=0;j--)
    {
        if (cnt[j]>=m)
        {
            cout<<j<<"\n";
            return;
        }
    }
}
void solve(){
    ans=a[n];
    for (int i=n;n-i+1<=m;i--)
    {
        ans=ans&a[i];
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if (n<=20)
    {
        solve1();
        return 0;
    }
    if (n<=2000&&m==1)
    {
        solve2();
        return 0;
    }
    if (n<=2000&&m==2)
    {
        solve3();
        return 0;
    }
    if (n<=2000&&m==n)
    {
        solve4();
        return 0;
    }
    if (m==n-1)
    {
        solve5();
        return 0;
    }
    if (f())
    {
        solve6();
        return 0;
    }
    solve();
    return 0;
}
