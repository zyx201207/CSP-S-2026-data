#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],sl[1048580],ans;
bool fg1,fg2,fg3,fg4,fg5,fg6;
bool b[25];
bool is_2m(ll x)
{
    if(x==1)
    {
        return false;
    }
    while(x>1)
    {
        if(x%2==1)
        {
            return false;
        }
        x/=2;
    }
    return true;
}
ll log2(ll x)
{
    ll sum=0;
    while(x>1)
    {
        sum++;
        x/=2;
    }
    return sum;
}
ll two_m(ll x)
{
    ll sum=1;
    for(int i=1;i<=x;i++)
    {
        sum*=2;
    }
    return sum;
}
void dfs(ll lev)
{
    //cout<<lev<<endl;
    if(lev>n)
    {
        bool flag=false;
        ll sum=0,cnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(b[i])
            {
                cout<<i<<" ";
                cnt++;
                if(!flag)
                {
                    sum=a[i];
                    flag=true;
                }
                else
                {
                    sum=sum&a[i];
                }
                cout<<sum<<" ";
            }
            if(cnt==m)
            {
                break;
            }
        }
        cout<<endl;
        if(cnt<m)
        {
            return;
        }
        ans=max(ans,sum);
        return;
    }
    dfs(lev+1);
    b[lev]=true;
    dfs(lev+1);
    b[lev]=false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ans=0;
	fg1=fg2=fg3=fg4=fg5=fg6=true;
	if(n>20)
    {
        fg1=false;
    }
    if(m!=1)
    {
        fg2=false;
    }
    if(m!=n)
    {
        fg3=false;
    }
    if(m!=2)
    {
        fg4=false;
    }
    if(!is_2m(n))
    {
        fg6=false;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i-1)
        {
            fg6=false;
        }
        if(!is_2m(a[i]+1)||a[i]==0)
        {
            fg5=false;
        }
        sl[a[i]]++;
    }
    if(fg1)
    {
        dfs(1);
        cout<<ans;
        return 0;
    }
    if(fg2)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(fg3)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(fg4)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(fg5)
    {
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    if(fg6)
    {
        cout<<n-two_m((is_2m(m)==true?log2(m):log2(m)+1));
    }
    return 0;
}
