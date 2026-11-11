#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5;
ll n,m,ans;
ll a[MAXN+5];
ll gp[MAXN+5];
ll b[MAXN+5];
ll maxn=LONG_LONG_MIN;
ll minn=LONG_LONG_MAX;
map<ll,int> mp;
bool pd1()
{
    ll gap=a[2]-a[1];
    for(int i=2;i<=n;i++)
        if(a[i]-a[i-1]!=gap)
            return false;
    return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i],mp[a[i]]++;
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
	sort(a+1,a+n+1);
	if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            ll sum=0;
            ll cnt=0;
            for(int j=i;j>=1;j--)
            {
                if(sum+a[i]-a[j]>m)
                    break;
                sum+=a[i]-a[j],cnt++;
            }
            //cout<<cnt<<" ";
            ans=max(ans,cnt);
        }
        //cout<<endl;
        cout<<ans;
    }
	else if(pd1())
    {
        ll gap=a[2]-a[1],cnt=0,sum=0;
        for(int i=n;i>=1;i--)
        {
            if(sum+a[n]-a[i]>m)
                break;
            sum+=a[n]-a[i],cnt++;
        }
        cout<<cnt;
    }
    else
    {
        int ct=0;
        a[n+1]=a[n]-1;
        for(int i=1;i<=n;i++)
            if(a[i]!=a[i+1])
                b[++ct]=a[i];
        for(int i=1;i<=ct;i++)
        {
            ll sum=0;
            ll cnt=0;
            for(int j=i;j>=1;j--)
            {
                if(sum+(b[i]-b[j])*mp[b[j]]>m)
                {
                    ll gpp=m-sum;
                    ll gpt=b[i]-b[j];
                    cnt+=gpp/gpt;
                    break;
                }
                sum+=(b[i]-b[j])*mp[b[j]],cnt+=mp[b[j]];
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
	return 0;
}
