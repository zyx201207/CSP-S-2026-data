#include<bits/stdc++.h>
using namespace std;
int n,m,maxs=0;
bool a[200005][35],biao[200005]={0};
void f(int i,long long k)
{
    int w=1;
    while(k>0)
    {
        a[i][w]=k%2;
        k/=2;
        w++;
    }
    maxs=max(maxs,w);
}
long long f2(int i)
{
    long long t=1,ans=0;
    for(int j=1;j<=maxs;j++)
    {
        ans=ans+t*a[i][j];
        t*=2;
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
        long long k;
        cin>>k;
        f(i,k);
        for(int j=maxs;j>=1;j--)
        {
            //cout<<a[i][j];
        }
        //cout<<endl;
    }
    //cout<<maxs<<" ";
    for(int j=maxs;j>=1;j--)
    {
        long long k=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==1&&biao[i]==0)
            {
                k++;
            }
        }
        if(k>=m)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i][j]==0)
                {
                    biao[i]=1;
                }
            }
        }
    }
    long long ans=pow(2,32)-1ll;
    for(int i=1;i<=n;i++)
    {
        if(biao[i]==0)
        {
            //cout<<i;
            ans=ans&f2(i);
        }
    }
    cout<<ans;
    return 0;
}
