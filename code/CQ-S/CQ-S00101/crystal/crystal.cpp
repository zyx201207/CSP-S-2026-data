#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n;long long m;//128
long long a[500005];
signed main(){
	//printf()
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	long long sum=0;
	int l=1,r=1;
	for(int i=2;i<=n;i++){
		sum+=1ll*(r-l+1)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
		}
		r++;
		ans=max(ans,r-l+1); 
	}
	cout<<ans<<'\n';
	
	return 0;
}

