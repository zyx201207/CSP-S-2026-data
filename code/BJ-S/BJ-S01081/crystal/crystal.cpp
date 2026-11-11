#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool vis=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n-1;i++)
    {
        if(a[i+2]-a[i+1]!=a[i+1]-a[i]) vis=false;
    }
    if(vis)
    {
        int ans=0,t=m/(a[2]-a[1]),tmp=0;
        while(t>=tmp)
        {
            t-=tmp;
            ans++;
            tmp++;
        }
        cout<<ans;
        return 0;
    }
    long long maxx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            b[j]=a[i]-a[j];
        }
        sort(b+1,b+i+1);
        for(int j=1;j<=i;j++)
        {
            b[j]+=b[j-1];
        }
        long long t=upper_bound(b+1,b+i+1,m)-b-1;
        maxx=max(maxx,t);
    }
    cout<<maxx;
    return 0;
}
