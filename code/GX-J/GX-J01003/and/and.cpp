#include<bits/stdc++.h>
using namespace std;
long long n,m,nextn,powmax,ans;
struct xx
{
    long long num;
    bool x=1;
    bool flag=1;
}a[200001];
bool cmp(xx a,xx b)
{
    if(a.flag=0)return 0;
    return a.num>b.num;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    nextn=n;
    for(int i=1;i<=n;i++){cin>>a[i].num;a[i].num;}
    sort(a+1,a+n+1,cmp);
    for( powmax=1;powmax<=a[1].num;powmax*=2);
    for(;powmax!=1;powmax/=2)
    {
        //cout<<n<<" ";
        nextn=n;
        for(int i=1;i<=n;i++)
        {
            if(a[i].num%powmax<powmax/2){a[i].x=0;nextn--;}
            else a[i].x=1;
        }

        if(nextn>=m)
        {
            for(int i=1;i<=n;i++)a[i].flag=a[i].x;
            ans+=powmax;
            sort(a+1,a+n+1,cmp);
            n=nextn;
        }

    }
    cout<<ans/2;
    return 0;
}
//mod 2^x,<2^(x-1):out->
