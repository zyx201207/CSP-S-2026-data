#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005];
int d[5005][5005];
long long maxn=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=5000)
    {
        int maxans=0;
        for(int i=1;i<=n;i++)
        {
            int nnd=0,j=i;
            while(1)
            {
                if(j>0&&nnd+a[i]-a[j]<=m) j--,nnd+=(a[i]-a[j]);
                else break;
            }
            maxans=max(maxans,i-j+1);
        }
        cout<<maxans;
    }
    else
    {
        long long d=a[2]-a[1];
        long long num=m/d;
        long long i=1;
        while(i*(i+1)/2<=num) i++;
        cout<<i;
    }
}
