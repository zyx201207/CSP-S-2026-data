#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n,i) for(int i=1;i<=n;i++)
#define forlr(l,r) for(int i=l;i<=r;i++)
#define forlrj(l,r,i) for(int i=l;i<=r;i++)
#define ford(n) for(int i=n;i>=1;i--)
#define fordj(n,j) for(int i=n;i>=1;i--)
#define forlrd(r,l) for(int i=r;i>=l;i--)
#define forlrdj(r,l,i) for(int i=r;i>=l;i--)

bool isPrime(int n)
{
    if(n<2)return 0;
    forlr(2,sqrt(n))return 0;
    return 1;
}

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

ll qpow(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    ll c=qpow(a,b/2,mod);
    ll d=(c*c)%mod;
    if(b%2==0)return d;
    else return (d*a)%mod;
}

//Oct31==Dec25?

ll n,m,a[500005],b[500005];

bool check(int k)
{
    ll s=0,ms=2e18;
    fori(k-1)s+=a[i];
    forlr(k,n)
    {
        s+=a[i];
        ll t=a[i]*k-s;
        if(t<ms)ms=t;
        s-=a[i-k];
        //printf("%d %d;",s,t);
    }
    //printf(",ms=%d\n",ms);
    if(m>=ms)return 1;
    return 0;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    fori(n)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    //fori(n)cout<<a[i]<<" ";
    //cout<<"\n";
    fori(n)b[i]=a[i]-a[i-1];

    //BINARY SEARCH
    int l=1,r=n,mid=(l+r+1)/2;
    while(l<r)
    {
        //printf("l=%d,r=%d,mid=%d\n",l,r,mid);
        if(check(mid))
        {
            l=mid;
            mid=(l+r+1)/2;
        }
        else
        {
            r=mid-1;
            mid=(l+r+1)/2;
        }
    }
    cout<<mid;
}
