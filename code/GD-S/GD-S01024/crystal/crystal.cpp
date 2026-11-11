#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5; 
int n,m,a[N],ans,res;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		res+=(i-l)*(a[i]-a[i-1]);
		while(res>m) res-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
