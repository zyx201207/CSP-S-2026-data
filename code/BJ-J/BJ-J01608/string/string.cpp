#include<bits/stdc++.h>
using namespace std;
long long ans,a[200005],n,c;
char v[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>v[i];
    int i=1;
    while(i<n)
    {
        if(v[i]!=v[n]&&a[i]>=a[n])ans+=a[n];
        else if(v[i]!=v[n])ans+=a[i];
        c=a[i]-a[n];
        a[n]-=a[i];
        a[i]=c;
        if(a[i]<=0)i++;
        if(a[n]<=0)n--;
    }
    cout<<ans;
    return 0;
}