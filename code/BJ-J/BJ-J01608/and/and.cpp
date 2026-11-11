#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],t[35],b[200005][35],c[35],ans[200005],mx2,d;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    c[0]=1;
    for(int i=1;i<31;i++)c[i]=c[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int cnt=0;
        while(a[i])
        {
            if(a[i]%2==1)
            {
                t[cnt]++;
                b[i][cnt]++;
            }
            a[i]/=2;
            cnt++;
        }
    }
    for(int i=0;i<=30;i++)
        if(t[i]<m)
            for(int j=1;j<=n;j++)
                if(b[j][i])b[j][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=30;j++)
            if(b[i][j])mx2=max(mx2,j);
    for(int i=1;i<=n;i++)if(b[i][mx2]==0)for(int j=0;j<=30;j++)if(b[i][j])t[j]--;
    for(int i=0;i<=30;i++)
        if(t[i]<m)
            for(int j=1;j<=n;j++)
                if(b[j][i])b[j][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=30;j++)if(b[i][j])ans[i]+=c[j];
    sort(ans+1,ans+n+1);
    d=ans[n];
    for(int i=n-1;i>=n-m+1;i--)d=d&ans[i];
    cout<<d;
    return 0;
}