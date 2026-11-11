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

int c,n,t,d,x[500005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        fori(n)scanf("%d",&x[i]);
        int s=x[2]-x[1];
        cout<<n-(d/s)<<"\n";
    }

}
