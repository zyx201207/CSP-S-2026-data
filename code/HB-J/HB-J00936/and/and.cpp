#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=0,a[200010];
int and1(int x,int y)
{
    int p=1,q=1,ans=0,a[10],b[10],c[10];
    while(x>0)
    {
        a[p]=x%2;
        x/=2;
        p++;
    }
    while(y>0)
    {
        b[q]=y%2;
        y/=2;
        q++;
    }
    p--;
    q--;
    for(int i=1;i<=max(p,q);i++)
    {
        if(a[i]==b[i]&&a[i]==1)
        {
            ans+=pow(2,i-1);
            continue;
        }
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    maxn=0;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,and1(a[i],a[j]));
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        maxn=a[1];
        for(int i=1;i<=n;i++)
        {
            maxn=and1(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+1+n);
    cout<<a[m];
    return 0;
}
