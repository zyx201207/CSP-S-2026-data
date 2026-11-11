#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,l,r,ans;
ll m,now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	for(l,r=1;r<=n;r++){
		now+=(a[r]-a[r-1])*(r-l);
		while(now>m){
			now-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
