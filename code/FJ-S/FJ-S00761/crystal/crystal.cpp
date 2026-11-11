#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=500005;
ll a[N];
ll diff[N];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m; cin>>n>>m;
	ll d;cin>>a[0];diff[0]=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		diff[i]=a[i]-a[i-1];
	}
	sort(a,a+n);
	int ans=1;
	for(int i=1;i<n;i++){
		ll sum=0;int cnt=0;
		
		for(int j=i-1;j>=0;j--){
			if (sum+a[i]-a[j]>m) break;
			sum+=a[i]-a[j];cnt++;
			
		}
		ans=max(ans,cnt+1);
		
	}
	cout<<ans<<'\n';
	return 0;
	
}
