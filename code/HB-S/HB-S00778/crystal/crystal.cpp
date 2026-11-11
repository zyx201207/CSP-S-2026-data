#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int a=0;int b=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if (c=='-')
        {
            b=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
int n,m;
int a[500005];
int b[500005];
int ans,bz,bz1;
int cnt1=1;int cnt2=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for (int i=1;i<n;i++)
    {
        if (ans>=m)
            break;
        ans+=i*(abs(a[i]-a[i+1]));
        a[i]+=(abs(a[i]-a[i+1]));
        bz=abs(a[i]-a[i+1]);
        cnt1++;
    }
    if(ans>m)
    {
        a[cnt1]-=bz;
        cnt1--;
    }
    int ans1=0;
    for (int i=cnt1;i<n;i++)
    {
        if(a[i+1]==a[cnt1])
        {
            ans1++;
        }
    }
    cnt1+=ans1;
    ans=0;
    for (int i=n;i>=2;i--)
    {
        if (ans>=m)
            break;
        ans+=i*(abs(b[i]-b[i-1]));
        b[i-1]-=(abs(b[i]-b[i-1]));
        int bz1=abs(b[i]-b[i-1]);
        cnt2++;
    }
    if(ans>m)
    {
        b[n-cnt2+1]+=bz1;
        cnt2--;
    }
    int ans2=0;
    for (int i=n-cnt2;i>=1;i--)
    {
        if(b[i]==b[n-cnt2+1])
        {
            ans2++;
        } 
    }
    cnt2+=ans2;
    cout<<max(cnt1,cnt2)<<endl;
    return 0;
}