#include<bits/stdc++.h>
#define int long long
#define pb push_back 
#define endl "\n"
using namespace std;
const int N=2e5+5;
vector<int>d; 
int n,m,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	cin>>a[i],d.pb(i);
	int ans=0;
	for(int i=29;~i;--i)
	{
		int cnt=0;
		for(auto j:d)
		if(a[j]>>i&1) ++cnt;
		if(cnt<m) continue;
		ans+=(1<<i);
		vector<int>_{};
		for(auto j:d)
		if(a[j]>>i&1) _.pb(j);
		d=_;
	}
	cout<<ans;
	return 0;
} 
/*
5 3
31 3 1 15 7
*/
