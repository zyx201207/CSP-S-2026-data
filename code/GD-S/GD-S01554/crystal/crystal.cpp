#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,m;
long long a[512345];
ll p[512345];
bool check(int cur,int c) {
	return ((c*a[cur]) - (p[cur] - p[cur-c]) ) <= (m); 
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;++i) p[i] = p[i-1] + a[i];
//	for(int i = 1;i<=n;++i) cout<<p[i]<<' '<<a[i]<<endl;
	int ans = 1;
	for(int i = 1;i<=n;++i) {
		//全部升级为i
		int lft = 1;int rht = i;int tmp = 1;
		while(lft<=rht) {
			int mid = (lft + rht) >> 1;
			if(check(i,mid)) {
				tmp = mid;
				lft = mid+1;
			} else rht = mid - 1;
		}//cout<<tmp<<endl;
		ans = max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
