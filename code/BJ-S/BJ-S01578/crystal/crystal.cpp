#include<iostream>
#include<algorithm>
using namespace std;

long long a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long cha;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cha=a[2]-a[1];
    sort(a+1,a+n+1);
    long long cnt=1;
    while(m-cha>=0)
    {
        m-=cha;
        cnt++;
        if(m-cha>=0)
        {
            m-=cha;
            cnt++;
        }
        cha*=2;
    }
    cout<<cnt;
    return 0;
}
