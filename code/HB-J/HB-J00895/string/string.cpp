#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n,j) for(int j=1;j<=n;j++)
#define forlr(l,r) for(int i=l;i<=r;i++)
#define forlrj(l,r,j) for(int j=l;j<=r;j++)
#define ford(i) for(int i=n;i>=1;i--)
#define fordj(n,j) for(int j=n;j>=1;j--)
#define forlrd(r,l) for(int i=r;i>=l;i--)
#define forlrdj(r,l,j) for(int j=r;j>=l;j--)

bool isPrime(int n)
{
    if(n==0||n==1)return 0;
    forlr(2,sqrt(n))
    {
        if(n%i==0)return 0;
    }
    return 1;
}

ll a[200005],n,p,q;
char c[200005];


int main()
{

    //**
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //*/
    cin>>n;
    fori(n)
        scanf("%lld %c",&a[i],&c[i]);

    p=1;
    q=n;
    ll ans=0;
    while(1)
    {
        if(p>=q)break;
        if(a[p]>a[q])
        {
            if(c[p]!=c[q])ans+=a[q];
            a[p]-=a[q];
            q--;
        }
        else if(a[p]<a[q])
        {
            if(c[p]!=c[q])ans+=a[p];
            a[q]-=a[p];
            p++;
        }
        else
        {
            if(c[p]!=c[q])ans+=a[p];
            p++;
            q--;
        }
        //printf("#%lld\n",ans);
    }
    cout<<ans;
}
