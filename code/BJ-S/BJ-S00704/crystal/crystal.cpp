#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005],sum,ans,maxn;
int main()
{
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        sum=a[i],ans=1;
        int i1=i;
        while((ans+1)*a[i]<=sum+m)
        {
            ans++;
            sum+=a[i1--];
            if(i1==1) break;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}