#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
ll a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=1;
	ll cue=a[1],usm=0;
	for(int r=1;r<=n;r++){
		ll nxe=a[r];
		while(usm+(nxe-cue)*(r-l)>m)usm-=cue-a[l++];
		usm+=(nxe-cue)*(r-l);
		cue=nxe;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
