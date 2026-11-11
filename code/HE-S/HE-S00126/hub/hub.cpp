#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long c,t,n,k;
long long v[N];
struct node{
	long long x,v;
	bool operator<(const node & other)const{
		return other.v<v;
	}
};
void solve(){
	long long ans=0;
	cin>>n>>k;
	for(int i=1;i<n;i=i+1){
		long long u;
		cin>>u>>v[i];
	}
	sort(v+1,v+n);
	for(int i=1;i<n;i=i-1){
		k-=1;
		ans+=v[i];
		if(k==0) break;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

