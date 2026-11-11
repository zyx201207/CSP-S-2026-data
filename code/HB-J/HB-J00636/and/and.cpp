#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long ans;
void dfs(int i,int j,long long x)
{
    if(j==m)
    {
        ans=max(ans,x);
        return ;
    }
    if(i>n)
    {
        return ;
    }
    //cout<<i<<" "<<j<<" "<<a[i]<<endl;
    dfs(i+1,j,x);
    dfs(i+1,j+1,x&a[i]);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long all=(1<<21)-1;
    long long maxn=0;
    bool b=0;
    int a4=0,a3=0,a2=0,a1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        all&=a[i];
        if(a[i]>4)
        {
            b=1;
        }
        if(a[i]==4)
        {
            a4++;
        }
        if(a[i]==3)
        {
            a3++;
        }
        if(a[i]==2)
        {
            a2++;
        }
        if(a[i]==1)
        {
            a1++;
        }

        maxn=max(maxn,a[i]);
    }
    if(m==n)
    {
        cout<<all;
    }
    if(n<=20)
    {
        dfs(1,0,(1<<21)-1);
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        long long cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=max(a[i]&a[j],cnt);
            }
        }
        cout<<cnt;
        return 0;
    }
    if(b)
    {
        if(a4>=m)
        {
            cout<<4;
            return 0;
        }
        else if(a3>=m)
        {
            cout<<3;
            return 0;
        }
        else if(a2>=m||a3+a2>=m)
        {
            cout<<2;
            return 0;
        }
        else
        {
            cout<<1;
            return 0;
        }
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
