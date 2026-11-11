#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int maxn=5e5+5;

int n,m,a[maxn];
int diff[maxn],sum[maxn];
int ans;

signed main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) {
		
		int num=0,len=0;
		
		for(int j=i-1;j>=1;j--) 
			if(num+a[i]-a[j]<=m) num+=(a[i]-a[j]),len++;
			else break; 
		ans=max(ans,len+1);
	}
	
	cout<<ans;
	
	return 0;
}
