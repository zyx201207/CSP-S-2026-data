#include<bits/stdc++.h>
using namespace std;
long long m,n,l,r,mid;
long long a[500005];
long long qz[500005];
bool check(int s)
{
    long long cnt=0,mcnt=LLONG_MAX;
    for(int i=s;i<=n;i++)
    {
    cnt=(a[i]*s)-(qz[i]-qz[i-s]);
mcnt=min(mcnt,cnt);
cnt=0;
    }

    if(mcnt>m)
    {
    return 0;
    }return 1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        qz[i]=qz[i-1]+a[i];
    }
    if(!check(1))
    {
        cout<<0;
        return 0;
    }
l=1;
r=n;
while(l<r)
{long long mid=(l+r+1)/2;
if(check(mid))
{
    l=mid;
}
else{
    r=mid-1;
}
}
cout<<l<<endl;
return 0;
}
