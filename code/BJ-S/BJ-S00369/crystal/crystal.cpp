#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long x=n/2;
    //cout<<a[x]<<endl;
    for(long long i=0;i<x;i++)
    {
        b[i]=a[x]-a[i];
    }
    /*for(int i=0;i<x;i++)
    {
        cout<<b[i]<<" ";
    }*/
    long long cishu=0,ans=0,maxn=-1;
    for(long long i=1;i<n;i++)
    {
        for(long long j=i;j>=0;j--)
        {
            ans+=b[j];
            cishu++;
            if(ans>m)
            {
                ans-=b[j];
                cishu--;
                break;
            }
            else if(ans==m)
            {
                break;
            }
        }
        cishu=x-cishu;
        maxn=max(maxn,cishu);
    }
    for(long long i=x;i<n;i++)
    {
        if(a[i]==a[x]) maxn++;
    }
    cout<<maxn+1;
    return 0;
}
