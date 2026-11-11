#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,xx=0,yk=0,kl=0,nu=0,cnt=0,cn=1;
ll a[200005];
bool cmp(ll x,ll y)
{
    return x>y;
}
long long d(ll aa,ll bb)
{
    ll z = 1;
    while(aa!=0)
    {
        xx =xx+ (aa%2)*z;
        z*=10;
        aa/=2;
    }
    z = 1;
    while(bb!=0)
    {
        yk =yk+ (bb%2)*z;

        z*=10;
        bb/=2;
    }
    long long k = max(xx,yk);
    long long kk = min(xx,yk);
    long long s=1;
    while(k!=0)
    {
        //cout<<k<<" "<<kk;
        if((k%10==kk%10)&&(k%10)!=0) kl = kl+1*s;
        else kl = kl+0*s;
        s*=10;
        k/=10,kk/=10;
        nu++;
    }

    cnt=0;
    cn=1;
    for(int i=0;i<=nu-1;i++)
    {
        //for(int j=1;j<=i;j++)
        //{
            //cn*=2;
            //cout<<cn<<" ";
        //}
        cnt = cnt+(kl%10)*cn;
        //cout<<cnt<<" ";
        cn*=2;
        kl/=10;
    }

    return cnt;


}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);

    }
    long long an=0;
    sort(a+1,a+n+1,cmp);
    if(m==n-1)
    {
        cout<<a[n-1];
    }
    for(int i=1;i<=m;i++)
    {
        if(i==1) an = a[i];

        else
        {
            an = d(a[i],an);

        }
    }
    cout<<an;
    return 0;
}
