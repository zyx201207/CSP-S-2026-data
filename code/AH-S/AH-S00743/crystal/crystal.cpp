#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
bool check(int l,int r)
{
    int mid=r;
    long long sum=0;
    for(int i=l;i<=r;i++)
    {
        sum+=abs(a[i]-a[mid]);
        if(sum>m)
        {
            return 0;
        }
    }
    if(sum<=m)
    {
        //cout<<l<<" "<<r<<" "<<sum<<endl;
        return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    long long maxx=-1;
    bool flaga=1;
    bool flagb=1;
    long long c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,abs(a[i]));
        if(a[i]!=i)
        {
            flaga=0;
        }
        if(i==2)
        {
            c=a[i]-a[i-1];
        }
        else if(i>2)
        {
            if(a[i]-a[i-1]!=c)
            {
                flagb=0;
            }
        }
    }
    if(flaga||flagb)
    {
        int ans=0;
        int l=1;
        int r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]-a[1]>m)
            {
                r=mid-1;
            }
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
    }
    else if(n<=5000)
    {
        sort(a+1,a+1+n);
        int l=1;
        int r=2;
        int ans=1;
        while(r<=n)
        {
            if(check(l,r))
            {
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                l++;
            }
        }
        cout<<ans;
        return 0;
    }
    else if(maxx<=100)
    {
        int t[205];
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            int x=a[i]+101;
            t[x]++;
        }
        int ans=1;
        for(int i=1;i<=201;i++)
        {
            int cnt=0;
            long long sum=0;
            for(int j=i;j>=1;j--)
            {
                long long num=t[j];
                long long cha=i-j;
                long long need=t[j]*cha;
                if(m>=need+sum)
                {
                    sum+=need;
                    cnt+=t[j];
                }
                else
                {
                    cnt=cnt+(m-sum)/cha;
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    else
    {
        int ans=n;
        cout<<ans;
    }
    return 0;
}
