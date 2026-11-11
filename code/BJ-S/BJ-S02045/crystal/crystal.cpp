#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define maxn 500010
//g++ crystal.cpp -o crystal -Wall -Wextra -Wshadow -Wconversion

int n,m;
int a[maxn],sum[maxn],pre[maxn];

int midsch(int x)
{
    int l=1,r=x-1,mid=(l+r)/2;
    while(l<=r)
    {
// cerr<<x<<" "<<l<<" "<<r<<" "<<mid<<endl; 
        mid=(l+r)/2;
        if(((a[x]*((x-1)-mid+1))-(sum[x-1]-sum[mid-1]))<=m) r=mid;
        else l=mid+1;
// cerr<<"search : "<<x<<" "<<l<<" "<<r<<" "<<mid<<endl;
        if(l==r) break;
    }
    return l;
}

bool cmp(int x1,int x2)
{return x1<x2;}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    if(m==0)
    {
        cout<<1;
        return 0;
    }


    for(int i=1;i<=n;i++) {cin>>a[i];}
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

//  for(int i=1;i<=n;i++) cerr<<sum[i]<<" ";
//  cerr<<endl;
    // for(int i=n;i>=1;i--) pre[i]=pre[i+1]+a[i];


    int ans=0;
    for(int i=2,nowsum=0,getmidsch=0;i<=n;i++)
    {
        getmidsch=midsch(i);
        nowsum=i-getmidsch+1;
// cerr<<i<<" "<<getmidsch<<" "<<nowsum<<endl;
        ans=max(ans,nowsum);
    }
    cout<<ans;
    return 0;   
}