#include<iostream>
#include<algorithm>
#include<list>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int N=500005;
long long n;
long long a[N];
long long m,used,ans;
int main()
{
    //freopen("/home/rdfz/crystal/crystal3.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=0,r=1;
    while(r<n)
    {
        l++;
        if(l!=1) used-=a[r]-a[l-1];
        while(r<=n&&m>=used+1ll*(r-l+1)*(a[r+1]-a[r]))
        {
            used+=1ll*(r-l+1)*(a[r+1]-a[r]);
            r++;
        }
        //cout<<l<<"~"<<r<<'\n';
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    cout.flush();

    return 0;
}
