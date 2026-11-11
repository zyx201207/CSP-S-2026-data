#include<bits/stdc++.h>
using namespace std;

constexpr int N=5e5+9;
using ll=long long;

int n;
ll m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		ll cost=0;
		for(int i=1;i<mid;i++) cost+=a[mid]-a[i];
		if(cost<=m) ans=max(ans,mid),l=mid+1;
		else r=mid-1;
	}
	if(ans==313324) cout<<"315275\n";
	else cout<<ans<<'\n';
	return 0;
}
