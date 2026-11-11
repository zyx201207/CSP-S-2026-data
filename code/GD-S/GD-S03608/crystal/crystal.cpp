#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,ans=0;
	ll sum=0;
	for(int i=2;i<=n;i++){
		sum=(i-l)*(a[i]-a[i-1])+sum;
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
		} 
		ans=max(ans,i-l+1);
	} 
	cout<<ans;
	return 0;
}
