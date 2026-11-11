#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long m,cnt=0,ans=0,maxa=0,sum=0,num=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long b[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) b[i][j]=a[j]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=0,cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(b[j][i]>0&&ans+b[j][i]<=m) ans+=b[j][i],cnt++,sum=b[j][i];
            else
            {
                if(ans==m&&cnt>maxa) maxa=cnt,num=a[j-1]+sum;
            }
        }
    }
    sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==num) sum++;
    }
    cout<<maxa+sum;
    return 0;
}
