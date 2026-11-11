//GZ-J00120 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void ss()
{
	ll n,m,mx=0;
	cin>>n>>m;
	vector<ll>a(n),nm;
	map<ll,ll>mp;
	for(int i=0;i<n;i++) cin>>a[i],mp[a[i]]++;
	bool fl=1;
	for(int i=0;i<n;i++)
    {
        if(a[i]!=i)
        {
            fl=0;break;
        }
    }
    if(fl)
    {
        ll ans,cnt=1;
        if(n%2==1)
        {
            if(m==n)
            {
                cout<<"0\n";
                return;
            }
            ans=a[n-2];
            for(int i=n-2;cnt<=m;i--) ans=ans&a[i],cnt++;
        }
        else
        {
            ans=a[n-1];
            for(int i=n-1;cnt<=m;i--) ans=ans&a[i],cnt++;
        }
        cout<<ans<<"\n";
        return;
    }
	for(int i=0;i<n;i++)
    {
        ll num=a[i];
        bool f=1;
        while(num)
        {
            if(num%2==1&&num/2!=0)
            {
                f=0;break;
            }
            num/=2;
        }
        if(f&&mp[a[i]]>=m) mx=max(mx,a[i]);
        if(!f) nm.push_back(a[i]);
    }
	sort(nm.begin(),nm.end(),greater<ll>());
	ll x=nm.size();
	if(x<m) cout<<mx<<"\n";
	else
    {
        ll cnt=nm[0];
	    for(int i=0;i<m;i++) cnt=cnt&nm[i];
	    cout<<max(cnt,mx)<<"\n";
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--) ss();
	return 0;
}
