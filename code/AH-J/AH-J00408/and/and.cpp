#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn=-0x3f3f3f3f,jkl,maxn1=-0x3f3f3f3f,flag;
long long check[25]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
bool cmp(int x,int y)
{
    return x>y;
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
        jkl=(jkl&a[i]);
        for(int j=0;j<=20;j++)
        {
            if(check[j]-1==a[i])
            {
                flag++;
            }
        }
    }
    if(m==1)
    {
        cout<<maxn;
        return 0;
    }
    if(flag==n)
    {
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(i==m)
            {
                cout<<a[i];
                return 0;
            }
        }
    }
    if(m==n)
    {
        cout<<jkl;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                maxn1=max(maxn1,(a[i]&a[j]));
            }
        }
        cout<<maxn1;
        return 0;
    }
    if(maxn<=3)
    {
        int f1=0,f2=0,f3=0,f4=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                f1=1;
            }
            if(a[i]==1)
            {
                f2=1;
            }
            if(a[i]==2)
            {
                f3=1;
            }
            if(a[i]==3)
            {
                f4=1;
            }
        }
        if(f3==1&&f4==1)
        {
            cout<<2;
            return 0;
        }
        if(f2==1&&f4==1)
        {
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
}
