#include <bits/stdc++.h>
using namespace std;
int n,maxi;
long long m,a[500005];
long long b[500005];
long long c[500005];
long long bot[500005];
long long top[500005];
int f(int x){
    int l=0,r=x,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(bot[x]+top[mid]+mid*c[x]-top[0]>m)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        b[i]=a[i]-a[i-1];
        // printf("%lld ",b[i]);
    }
    // printf("\n");
    for(int i=0;i<n-1;i++)
    {
        c[i]=a[n-1]-a[i];
        // printf("%lld ",c[i]);
    }
    // printf("\n");
    for(int i=1;i<n;i++)
    {
        bot[i]=bot[i-1]+i*b[i];
        // printf("%lld ",bot[i]);
    }
    // printf("\n");
    for(int i=n-2;i>=0;i--)
    {
        top[i]=c[i]+top[i+1];
        // printf("%lld ",top[i]);
    }
    // printf("\n");
    int j;
    for(int i=0;i<n;i++)
    {
        j=f(i);
        // printf("%d ",j);
        maxi=max(i-j+1,maxi);
    }
    // printf("\n");
    printf("%d",maxi);
    return 0;
}