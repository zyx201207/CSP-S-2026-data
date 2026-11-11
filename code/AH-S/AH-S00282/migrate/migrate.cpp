#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll c,t,n,d,x[2000005];
int main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	F;
	ll i,j;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		unordered_map<ll,bool> mp;
		unordered_map<ll,int> bs;
		for(i=0;i<n;++i)cin>>x[i],mp[x[i]]=1;
		sort(x,x+n);
		for(i=j=0;i<n;++i){
			bs[x[i]]++;
			auto t=upper_bound(x,x+n,x[i]+d)-x;
			if(t<n&&t-i-1==2&&x[t]-x[t-1]<=d&&x[t-1]-x[i+1]<=d&&x[i+1]-x[i]<=d)j+=bs[x[i]];
			bs[x[i]+d]+=bs[x[i]];
		}
		cout<<j<<"\n";
	}
	return 0;
}
