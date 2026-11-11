#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx_ans=0;
	int ans=0;
	int r=n,l=n;
	ll sum=0;
	while(r>=1){
		while(sum<=m&&l>=1){
			sum+=(a[r]-a[l]);
			ans++;
			l--;
		}
		if(sum>m){
			sum-=(a[r]-a[l]);
			ans--;
			l++;
		}
		mx_ans=max(mx_ans,ans);
		sum-=(r-l)*(a[r]-a[r-1]);
		ans--;
		r--;
	}
	cout<<mx_ans;
	return 0;
}
 
