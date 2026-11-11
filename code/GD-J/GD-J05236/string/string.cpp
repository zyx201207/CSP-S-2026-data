#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fir first
#define sec second
using namespace std;
void solve()
{
	ll n,L=0;
	cin>>n;
	vector<ll> a(n+1);
	vector<char> b(n+1);
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i];
		L+=a[i];
		a[i]+=a[i-1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll beg=lower_bound(a.begin()+1,a.begin()+n,L-(a[i-1]+1)+1)-a.begin();
		ll end=lower_bound(a.begin()+1,a.begin()+n,L-a[i]+1)-a.begin();
		if(end<i)end=beg;
		for(int j=end;j<=beg;j++)
		{
			if(j==beg&&j==end&&b[i]!=b[j])ans+=(L-(a[i-1]+1)+1)-(L-a[i]+1)+1;
			else if(j==beg&&b[i]!=b[j])ans+=(L-(a[i-1]+1)+1)-(a[beg-1]+1)+1;
			else if(j==end&&b[i]!=b[j])ans+=a[end]-(L-a[i]+1)+1;
			else if(b[j]!=b[i])ans+=a[j]-a[j-1];
		}
		if(a[i]>=(L+1)/2)break;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie();
	ll T=1;//cin>>T;
	while(T--)solve();
	return 0;
}

