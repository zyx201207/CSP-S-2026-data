#include<bits/stdc++.h> 
#define int long long 
using namespace std;
int a[500005];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,t=0;
	for(int i=1;i<=n;i++){
		t+=(i-l)*(a[i]-a[i-1]);
		while(t>m)t-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
