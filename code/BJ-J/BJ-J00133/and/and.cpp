#include<bits/stdc++.h>
using namespace std;
int pw[35],a[200005],n,mx,m,ans[200005],b[35],cnt,tot=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=30;i++) pw[i]=pw[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    mx=30;
    for(int i=30;i>=1;i--)
    {
        if(a[n]<pw[i]) mx--;
        else break;
    }
    for(int i=0;i<=31;i++) b[i]=0;
    for(int i=1;i<=n;i++) ans[i]=1;
    for(int i=mx;i>=0;i--)
    {
        for(int j=1;j<=n;j++) if(ans[j]>1) ans[j]=1;
        cnt=0;
        for(int j=n;j>=1;j--)
        {
            if(ans[j]==0) continue;
            if(a[j]>=pw[i])
            {
                ans[j]++;
                cnt++;
            }
        }
        if(cnt>=m)
        {
            for(int j=1;j<=n;j++) ans[j]--;
            for(int j=1;j<=n;j++) a[j]-=pw[i];
            b[i]=1;
        }

    }
    for(int i=0;i<=30;i++) if(b[i]) tot+=pw[i];
    cout<<tot;
    return 0;
}
