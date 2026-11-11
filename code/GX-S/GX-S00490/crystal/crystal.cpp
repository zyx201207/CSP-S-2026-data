#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[1000000];
long long b[1000000],c[1000000],d[1000000];
long long pt(int i)
{
    long long s=d[i]-m;
    int sum=0;
    for(int j=0;j<i;j++)
    {
        sum++;
        int f=(j+1)*(a[i]-a[j])+d[j];
        if(f>=s) return i-sum+1;
    }
    return 1;

}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    c[0]=1;
    d[0]=0;
    for(int i=1;i<n;i++)
    {
        d[i]=d[i-1]+i*b[i];
    }
    for(int i=1;i<n;i++)
    {
        c[i]++;
        if(d[i]<=m) c[i]+=i;
        else if(d[i]>m) c[i]=pt(i);
        ans=max(ans,c[i]);
    }

    cout<<ans;
    return 0;
}
