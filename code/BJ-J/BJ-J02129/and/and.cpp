#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    if(m==1) ans=a[n];
    else if(m==n)
    {
        ans=a[n];
        for(int i=1;i<n;i++)
        ans=ans&a[i];
    }
    else if(m==2)
    {
        ans=a[n]&a[n-1];
        for(int i=n-2;a[i]>=ans;i--)
        {
            for(int j=1;j<=n-i;j++)
            {
                int t=a[i]&a[i+j];
                ans=max(ans,t);
            }
        }
    }
    else
    {
        ans=a[n];
        for(int i=1;i<m;i++)
        {
            ans=ans&a[n-i];
        }
        for(int i=n-m;a[i]>=ans;i--)
        {
            for(int j=1;j<=n-m-i+1;j++)
            {
                int t=a[j]&a[i];
                for(int k=1;k<m-1;k++) t=t&a[n-k];
                ans=max(ans,t);
            }
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}