#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,d;
int ans=1,cnt;
long long a[N],diff[N],sum[N],s[N],res;
bool flag=1,f=1;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(i==2)
            d=a[i]-a[i-1];
        if(i>2&&a[i]-a[i-1]!=d)
        {
            f=0;
        }
    }
    sort(a+1,a+1+n);
    //cout << flag << endl;
    if(f)
    {
        long long W=m;
        long long abc=0;
        long long x=1,cnt1=0;
        while(abc*d<m)
        {
            abc=(1+x)*x/2;
            x++;
        }
        if(abc*d>m)
        {
            cout << x-1 << endl;
            return 0;
        }
        else
        {
            cout << x << endl;
            return 0;
        }
    }
    diff[1]=0;
    sum[1]=0;
    for(int i=2;i<=n;i++)
    {
        diff[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+diff[i];
    }
    s[0]=0;
    s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    /*for(int i=n;i>=1;i--)
    {
        int j=i-1;
        res=a[i]*(i-j)-(s[i-1]-s[j-1]);
        cnt=i-j+1;
        while(res<m&&j>=1&&cnt>ans)
        {
            j--;
            res=a[i]*(i-j)-(s[i-1]-s[j-1]);
            cnt=i-j+1;
            ans=max(cnt,ans);
            printf("%d %d res:%lld cnt:%d ans:%d\n",i,j,res,i-j+1,ans);
        }
    }*/
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(i-j+1<ans)
                continue;
            res=a[i]*(i-j)-(s[i-1]-s[j-1]);
            if(res>m)
                continue;
            ans=max(ans,i-j+1);
            //printf("%d %d res:%lld cnt:%d ans:%d\n",i,j,res,i-j+1,ans);
        }
    }
    cout << ans << endl;
    return 0;
}


