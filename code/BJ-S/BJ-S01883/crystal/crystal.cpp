#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;ll m;
	cin>>n>>m;
	vl a(n);
	for(ll&v:a)cin>>v;
	sort(a.begin(),a.end());
	int ans=0;
	ll sum=0;
	for(int i=0,p=0;i<n;i++){
		sum+=a[i];
		while(p<=i&&(i-p+1)*a[i]-sum>m)sum-=a[p],p++;
		if(p<=i)ans=max(ans,i-p+1);
	}
	cout<<ans<<endl;
	
	return 0;
}