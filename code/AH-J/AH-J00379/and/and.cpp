#include<bits/stdc++.h>
using namespace std;
long long n,m,x,maxn=0;
long long b[200005], a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(maxn<=b[i])
            {
                maxn=b[i];
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            int cnt=1,sum=0,x;
            while(b[i]>0)
            {
                x+=b[i]%2*cnt;
                b[i]=b[i]/2;
                cnt=cnt*10;
            }
            a[i]=x;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int n=a[i]&&a[j];
                if(maxn<=n)
                {
                    maxn=n;
                }
            }
        }
        cout<<maxn;
    }
    return 0;
}
