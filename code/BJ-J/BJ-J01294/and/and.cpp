#include<iostream>
using namespace std;
long long n,m;
long long maxx;
long long yv(long long a,long long b)
{
    long long c=0;
    int cnt=0;
    while(a>0||b>0)
    {
        c+=min(a%2,b%2)*(1<<cnt);
        a/=2;
        b/=2;
        cnt++;
    }
    return c;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long sum=(1<<30)-1;
    while(n--)
    {
        long long a;
        cin>>a;
        sum=yv(sum,a);
        maxx=max(maxx,a);
    }
    if(m==n)
    {
        cout<<sum;
        return 0;
    }
    cout<<maxx;
    return 0;
}