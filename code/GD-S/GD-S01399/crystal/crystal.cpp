#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long c[500005];//cha
long long f[500005];
long long ans=0;
bool check(long long num,int point)
{
    long long ans1=0;
    for(int i=0;i<num;++i)
    {
        ans1+=c[point-i]*(num-i);
    }
    //cout<<num<<' '<<point<<' '<<"check:"<<ans1<<endl;
    if(ans1<=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        //cout<<a[i]<<' ';
        c[i]=a[i]-a[i-1];
    }
    //cout<<endl;
    for(int i=1;i<=n;++i)
    {
        long long l=1;
        long long r=i-1;
        while(l<=r)
        {
            long long minn=l+(r-l)/2;
            if(check(minn,i))
            {
                l=minn+1;
                ans=max(ans,minn+1);
            }
            else
            {
                r=minn-1;
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
