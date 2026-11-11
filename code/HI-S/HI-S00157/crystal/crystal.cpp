#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=1e5*5;
vector<ll> g[MAX];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a.begin(),a.end());
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			g[i].push_back(a[i]-a[j]);
	}
	
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll cs=m,cnt=0;
		for(int j=i-1;j>=0;j--){
			cs-=g[i][j];
			if(cs<0) break;;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
