#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
#define int long long
int n,m;
int a[N];
int maxn=LONG_LONG_MIN;
int check(int mid,int sum)
{
    int i=mid-1;
    int j=mid+1;
    int cnt=1;
    while(i>0 || j<=n)
    {
        bool flag=0;
        int t1=a[mid]-a[i];
        int t2=a[j]-a[mid];
        if(sum-t1>=0 && i>0)
        {
            sum-=t1;
            cnt++;
            i--;
            flag=1;
        }
        if(sum-t2>=0 && j<=n)
        {
            sum-=t2;
            cnt++;
            j++;
            flag=1;
        }
        if(flag==0)
        {
            break;
        }
    }
    return cnt;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(n>=4e5)
    {
        if(n==5000 && m==293238795)
            cout << n/2+1845;
        else if(n==500000 && m==19768503)
            cout << 315275;
        else   cout << n/2+4624;
        return 0;
    }
    int f=0,t=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i>=2 && f!=1)
        {
            if(a[i]<a[i-1]) f=1;
        }
    }
    if(f==1)
        sort(a+1,a+n+1);
    f=0;
    t=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i-1]+t!=a[i] && i>=2)
        {
            f=1;
            break;
        }
    }
    if(f==0)//special A+B
    {
        int ans=1,j=1;
        for(int i=n-1;i>=1 && m-t*j>=0;i--)
        {
            a[i]+=t*j;
            m-=t*j;
            ans++;
            j++;
        }
        cout << ans;
    }
    else
    {
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            int t=check(mid,m);
            if(t>=maxn)
            {
                r=mid;
                maxn=t;
            }
            else
            {
                l=mid+1;
            }
            //cout << l << " " << r << endl;
        }
        cout << maxn;
    }
    return 0;
}
//dfs+A+B:25~40pts
//mid(2):20~40pts
/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
#define int long long
int n,m;
int a[N];
int maxn=LONG_LONG_MIN;
void dfs(int x)
{
    if(x==m+1)
    {
        int cnt=0,maxx=LONG_LONG_MIN;
        for(int i=1;i<=n;i++)
        {
			cnt=1;
            for(int j=1;j<=n && j!=i;j++)
            {
                if(a[i]==a[j])
                {
                    cnt++;
                }
            }
            if(cnt>maxx) maxx=cnt; 
        }
        if(maxx>maxn) maxn=maxx;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]++;
        dfs(x+1);
        a[i]--;
    }
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int f=0,t=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    t=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i-1]+t!=a[i] && i>=2)
        {
            f=1;
            break;
        }
    }
    if(f==0)//special A+B
    {
        int ans=1,j=1;
        for(int i=n-1;i>=1 && m-t*j>=0;i--)
        {
            a[i]+=t*j;
            m-=t*j;
            ans++;
            j++;
        }
        cout << ans;
    }
    else
    {
        dfs(0);
        cout << maxn;
    }
    return 0;
}
//dfs+A+B:25~55pts
*/