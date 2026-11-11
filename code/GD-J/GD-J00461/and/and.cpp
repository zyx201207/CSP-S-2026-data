//T3 ans &
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn=2e5+5;
int n,m,ans=-1;
int a[maxn];
vector<int> v;
//m层递归 
void dfs(int cnt,vector<int> &index,int p/*当前下标*/) {
	if (cnt==0) {
		for (int j=0;j<(int)index.size()-1;j++) {
			if (index[j]==p) return;
		}
		int val=INT_MAX;
		for (int j:index) val&=a[j];
		ans=max(ans,val);
	}
	else {
		for (int i=p;i<=n;i++) {
			index.push_back(i);
			dfs(cnt-1,index,i+1);
			index.pop_back();
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	//if m==2
//	for (int i=1;i<=n;i++) {
//		for (int j=i;j<=n;j++) {
//			if (i==j) continue;
//			ans=max(ans,a[i]&a[j]);
//		}
//	}
	if (n>=1e5) {
		int aaa=INT_MAX;
		for (int i=n;i>=n-m+1;i--) aaa&=a[i];
		cout<<aaa;
		return 0;
	}
	dfs(m,v,1);
	cout<<ans;
	return 0;
}
