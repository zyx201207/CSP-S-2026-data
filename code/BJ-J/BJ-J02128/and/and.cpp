#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200005],n,m;
bool vis[25];
int num,maxx=0;
void dfs(int step)
{
    if(step>=n)
    {
        if(num==m)
        {
            int ans=2147483647;
            for(int i=1;i<=n;++i)
                if(vis[i])
                    ans=ans&a[i];
            maxx=max(maxx,ans);
        }
        return;
    }
    if(num<m)
    {
        vis[step+1]=1;
        num++;
        dfs(step+1);
        num--;
    }
    vis[step+1]=0;
    dfs(step+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxa=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    if(maxa<=4)
    {
        int x1=0,x2=0,x3=0,x4=0;
        for(int i=1;i<=n;++i)
        {
            switch(a[i])
            {
                case 1:x1++;break;
                case 2:x2++;break;
                case 3:x3++;break;
                case 4:x4++;break;
            }
        }
        if(x4>=m)cout<<4;
        else if(x3>=m)cout<<3;
        else if(x3+x2>=m)cout<<2;
        else if(x3+x1>=m)cout<<1;
        else cout<<0;
    }
    else if(m==1)
    {
        for(int i=1;i<=n;++i)
            maxx=max(maxx,a[i]);
        cout<<maxx;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=1;i<=n;++i)
            ans=ans&a[i];
        cout<<ans;
    }
    else if(m==2)
    {
        for(int i=1;i<=n-1;++i)
            for(int j=i+1;j<=n;++j)
                maxx=max(maxx,a[i]&a[j]);
        cout<<maxx;
    }
    else//must be the last case
    {
        num=0;
        dfs(0);
        cout<<maxx;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
