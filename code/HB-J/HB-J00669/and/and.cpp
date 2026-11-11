#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200010][40];
int b[200010],z[200010][40];
long long ans;
    int ant=200000000;
    int sum=0;

bool cmp(int x,int y)
{
    return x>y;
}



int main()
{
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int k,bb=b[i];
        for(k=1;bb>=1;k++)
        {
            z[i][k]=bb%2;
            bb/=2;
        }
        for(int j=1;j<=30;j++)
           a[i][k-j]=z[i][j];
    }
    for(int i=30;i>=0;i--)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j][i]==1)
            {
                sum++;
            }
        }
        if(sum>=m)
        {
            ant=min(ant,sum);
        }
    }
    for(int i=1;i<=30;i++)
    {
        ans*=2;
        bool pd=1;
        for(int j=1;j<=n;j++)
        {
            if(z[j][i]!=1)
                pd=0;
        }
        if(pd)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
