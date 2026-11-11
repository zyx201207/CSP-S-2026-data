#include<bits/stdc++.h>
using namespace std;

long long n,m,num[200005],a[200005],ans;

void choose(int cur)
{
    if (cur==m)
    {
        long long r=a[num[1]]&a[num[0]];
        for (int i=2;i<m;i++)
        {
            r=a[num[i]]&r;
        }
        ans=max(r,ans);
    }
    int start=(cur==0 ? 1 : num[cur-1]+1);
    for (int i=start;i<=n;i++)
    {
        num[cur]=i;
        choose(cur+1);
    }
}
bool cmp(long long l,long long r)
{
    int cnt1=0,cnt2=0;
    while(l>0)
    {
        if (l&1) cnt1++;
        l=l>>1;
    }
    while(r>0)
    {
        if (r&1) cnt2++;
        r=r>>1;
    }
    return cnt1>>cnt2;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n>=2000)
    {
        sort(a+1,a+n+1);
        long long r1=a[1]&a[2],r2=a[1]&a[2];
        for (int i=3;i<=m;i++)
        {
            r1=r1&a[i];
        }
        sort(a+1,a+n+1,cmp);
        for (int i=3;i<=m;i++)
        {
            r2=r2&a[i];
        }
        ans=max(r1,r2);
    }
    else choose(0);
    cout<<ans;
    return 0;
}

