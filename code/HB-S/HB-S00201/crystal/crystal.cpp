#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;

int n,m;
long long s[N];
long long arr[N];
long long C[N];

void solve()
{
    int ans=0;

    for(int i=2;i<=n;i++)//change to s[i]
    {
        int cnt=0;
        for(int j=i;j>=1;j--)
        {
            if(m>=s[i]-s[j])
            {
                m-=(s[i]-s[j]);
                s[j]=s[i];
                cnt++;
            }
        }

        ans=max(ans,cnt);
    }

    cout<<ans;
    return ;
}

int sum(int x)
{
    int res=0;
    for(int i=1;i<=x;i++)
    {
        res+=s[x]-s[i];
    }

    return res;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        C[s[i]]++;
    }

    sort(s+1,s+n+1);

    if(n<=5000)
    {
       solve();
        return 0;
    }

    bool flag=true;
    int cha=s[2]-s[1];
    for(int i=3;i<=n;i++)
    {
        if(s[i]-s[i-1]!=cha)
        {
            flag=false;
        }
    }

    if(flag)
    {
        int res=1;
        for(int i=1;i<=n;i++)
        {
            if(m-cha*i>=0)
            {
                m-=cha*i;
                res++;
            }
            else
            {
                break;
            }
        }

        cout<<res;
        return 0;
    }
    else
    {
        int l=1,r=n;
        int ans;
        while(l<=r)
        {
            int mid=l+r>>1;
            ans=mid;
            if(sum(mid)==m)
            {
                cout<<mid+C[s[mid]]-1;
                return 0;
            }
            if(sum(mid)<m)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }

        cout<<r;
    }

    return 0;
}

/*
Oct31==Dec25?
14 2
7 7 7 8 8 8 8 8 9 9 9 9 9 9
*/
