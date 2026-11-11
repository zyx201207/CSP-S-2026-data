#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
using namespace std;
const int N=5e5+5;
vector<int>d[N];
int n,m,a[N],h[N],cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	cin>>a[i],h[i]=1;
	for(int i=n;i;--i)
	d[a[i]].pb(i);
	for(int i=1;i<=n;++i)
	{
		d[a[i]].pop_back();
		if(d[a[i]].empty()) 
		{
			cnt[a[i]]+=h[i];
			h[i+1]+=h[i];
			continue;	
		}
		h[d[a[i]].back()]+=h[i];
	}
	for(int i=1;i<=m;++i)
	cout<<cnt[i]<<((i^m)?" ":"");
	return 0;
}

