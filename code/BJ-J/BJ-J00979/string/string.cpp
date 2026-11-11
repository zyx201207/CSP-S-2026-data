#include<bits/stdc++.h>
using namespace std;
char c[200010];
long long a[200010];
int n;
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1])a[i-1]+=a[i],i--,n--;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(c[l]!=c[r])ans+=min(a[l],a[r]);
        if(a[l]>a[r])a[l]-=a[r],r--;
        else a[r]-=a[l],l++;
    }
    printf("%lld\n",ans);
    return 0;
}
