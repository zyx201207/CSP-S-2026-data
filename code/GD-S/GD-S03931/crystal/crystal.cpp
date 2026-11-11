#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n;
ll m;
ll a[N];
queue<ll>q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	q.push(a[1]);
	ll sum=0,ans=0;
	ll mx=a[1];
	for(int i=2;i<=n;i++)
	{
		if(q.size()>ans)ans=q.size();
		while(q.size()>0&&(a[i]-mx)*q.size()+sum>m)sum-=mx-q.front(),q.pop();
		q.push(a[i]);
		sum+=(a[i]-mx)*(q.size()-1);
		mx=a[i];
	}
	if(q.size()>ans)ans=q.size();
	cout<<ans;
	/*ll ans=0;  二分 
	ll x=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])x++;
		else 
		{
			if(ans<x)ans=x;
			x=0;
		}
	}
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=l+r>>1;
		ll cnt=0;
		ll sum=0;
		for(int i=n;i>=1;i--)
		{
			if(a[mid]<a[i])continue;
			if(sum+(a[mid]-a[i])<=m)sum+=a[mid]-a[i],cnt++;
			else break;
		}
		if(cnt>ans)
		{
			ans=cnt;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;*/
	return 0;
}
/*数据 15：45 
5 8
-3 -1 2 2 7

4



5 100
-1000 -90 -1 3 1000

3

11 4
-1 -1 -1 -1 -1 6 6 8 100 1000 10000 20000

5
*/
