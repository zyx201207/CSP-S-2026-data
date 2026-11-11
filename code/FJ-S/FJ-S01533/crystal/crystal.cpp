#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=5e5+5;
int n,a[N],ans;
ll m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2;
	ll sum=0;
	while(l<=r&&r<=n){
		if(sum+(r-l)*(a[r]-a[r-1])<=m){
			sum+=(r-l)*(a[r]-a[r-1]);
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			sum-=a[r-1]-a[l];
			l++;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
