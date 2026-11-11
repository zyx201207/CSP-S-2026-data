#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005];
queue<ll> q;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	ll m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a+1,a+1+n);
	
	ll w=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		w+=(a[i]-a[i-1])*q.size();
		while(w>m) 
		{
			w-=a[i]-q.front();
			q.pop();
		}
		q.push(a[i]);
		ans=max(ans,(int)q.size());
	}
	
	cout<<ans;
	return 0;
}
